#include <iostream>
using namespace std;
/*静态成员函数，不能使用this，因为不需要对象就可以调用*/

class F{
	int n;
	int d;
	void reduce(){
		//约分
		int mcd = maxcd(n < 0 ? -n : n, d);
		if (mcd != 1) n /= mcd, d /= mcd;
	}
	
public:
	static int maxcd(int a, int b) {   //静态成员函数
		if (a == 0) return b;
		return maxcd(b % a, a);
	}
	F(int n = 0, int d = 1) :n(n), d(d){        //默认参数，初始化列表
		if (d == 0) throw "分母不能为零";
		reduce();
		cout << "F(" << n << '/' << d << "）\n";
	}

	friend ostream& operator<<(ostream& o, const F& f) {
		o << f.n << '/' << f.d;
		return o;
	}
	friend F operator+(const F& lh, const F& rh) {   //运算符重载,不加friend会报错？？
		F res(lh.n * rh.d + lh.d *rh.n ,lh.d * rh.d);  //+friend表明这个是一个外部的友元函数，所以参数有两个，不加会报错
		return res;
	}
	F operator*(const F& rh)const{				//成员函数，第一个操作数已经是当前对象了，所以只能传一个参数，对当前的对象加上const
		return F (n*rh.n, d*rh.d);				//匿名对象，直接把名字给省略掉了
	}

};

int main() {
	
	F f1;
	F f2(3);
	F f3(6, 12);

	cout << f1 << ',' << f2 << ',' << f3 << endl;
	cout << F::maxcd(12, 24) << endl;   //条用静态方法
	
	cout << f1 + f2 << ',' << f1 + f3 << endl;
	cout << f1 + f2 + f3 << endl;		//此时f1+f2是一个临时值，但是引用一个临时值，必须要有const,这里很容易出错
										//+ 如果在定义operator+时，参数不加const修饰，这里会有问题
	cout << f2*f3 << endl;

	cout << "~f1=" << ~f1;

	int a;
	cin >> a;
}