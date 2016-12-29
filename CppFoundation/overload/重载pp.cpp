#include <iostream>
using namespace std;
/*前++和后++的重载,后的操作需要一个int型的哑元
所以前++/--测效率要比后++/--高，一般最好用前
*/


class F{
	int n;
	int d;
	
public:
	
	F(int n = 0, int d = 1) :n(n), d(d){        //默认参数，初始化列表
	}

	friend ostream& operator<<(ostream& o, const F& f) {
		o << f.n << '/' << f.d;
		return o;
	}
	F& operator++() {
		n += d; return *this;
	}
	F operator++(int) { F old(*this); n += d; return old; }
	friend F& operator--(F& f){ f.n -= f.d; return f; }
	friend F operator--(F& f, int){
		F old(f); f.n -= f.d; return old;
	}

	operator double() {			//类型转换运算符函数，就不写了
		return 1.0*n / d;
	}
	operator bool() {
		return n != 0;
	}
};

void func1(F a) { cout << a << endl; }
int main() {

	F f1(2, 5), f2(4, 9), f3(7, 13);
	cout << ++f1 << endl;   //f1.operator++()
	cout << f2++ << endl;	//f2.opreator++(0)  这里都是以成员的方式重载的

	cout << --f3 << endl;	//operator--(f3)
	cout << f3-- << endl;	//operator--(f3, 0)

	cout << double(f1) << endl; //f1.operator double()
	cout << boolalpha << bool(f1) << endl;
	cout << F(3) << endl;  //匿名对象，不过也可以看成将3转换为F类型的对象
	cout << (F)5 << endl;
	func1(6);				//这里用实参初始化形参，实际上是F a(6)
	int a;
	cin >> a;
}