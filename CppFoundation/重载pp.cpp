#include <iostream>
using namespace std;
/*ǰ++�ͺ�++������,��Ĳ�����Ҫһ��int�͵���Ԫ
����ǰ++/--��Ч��Ҫ�Ⱥ�++/--�ߣ�һ�������ǰ
*/


class F{
	int n;
	int d;
	
public:
	
	F(int n = 0, int d = 1) :n(n), d(d){        //Ĭ�ϲ�������ʼ���б�
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

	operator double() {			//����ת��������������Ͳ�д��
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
	cout << f2++ << endl;	//f2.opreator++(0)  ���ﶼ���Գ�Ա�ķ�ʽ���ص�

	cout << --f3 << endl;	//operator--(f3)
	cout << f3-- << endl;	//operator--(f3, 0)

	cout << double(f1) << endl; //f1.operator double()
	cout << boolalpha << bool(f1) << endl;
	cout << F(3) << endl;  //�������󣬲���Ҳ���Կ��ɽ�3ת��ΪF���͵Ķ���
	cout << (F)5 << endl;
	func1(6);				//������ʵ�γ�ʼ���βΣ�ʵ������F a(6)
	int a;
	cin >> a;
}