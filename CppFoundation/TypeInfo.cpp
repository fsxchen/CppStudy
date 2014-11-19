#include <iostream>
#include <string>
#include <typeinfo>
/*
����ʱ����ʶ��RTTI
*/
using namespace std;

class A {
public:
	virtual void f() {
	
	}
};

class B : public A {};
class C : public B {};
class DDD : public A {};

int main() {
	A *p1 = new A, *p2 = new B, *p3 = new C, *p4 = new DDD, *p5 = new B;

	//cout << typeid(A).name() << endl;
	//cout << typeid(C).name() << endl;
	cout << typeid(*p2).name() << endl;
	cout << typeid(*p3).name() << endl;
	cout << (typeid(*p2) == typeid(*p5)) << endl;		//�Ƚ����������Ƿ���ͬ
	cout << typeid(*p2).before(typeid(*p1)) << endl;	//�Ƚ��ĸ�������ǰ��

	const type_info& t = typeid(*p4);
	cout << t.name() << endl;
	delete p1; delete p2; delete p3; delete p4; delete p5;

	int aaaa;
	cin >> aaaa;
}