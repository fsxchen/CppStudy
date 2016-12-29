#include <iostream>
#include <string>
using namespace std;

class A {
	double d;
};

class B:public A {
	double d;
public:
	void f() {}
};


class C{
	double d;
public:
	virtual void f() { cout << "C����麯��" << endl; }
	virtual void g() { cout << this << ", &d=" << &d << endl; }  //��������ַ֮���������ָ��ĵ�ֵַ
};

class D:public C {
	double d;
public:
	virtual void f() { cout << "D����麯��" << endl; }
	virtual void g() {}
	virtual void h() {}
	virtual void i() {}
	virtual void j() {}
};

int main() {
	//cout << sizeof(A) << endl;
	//cout << sizeof(B) << endl;
	//cout << sizeof(C) << endl;
	//cout << sizeof(D) << endl;
	A* p = new B;
	C* q1 = new C, *q2 = new D;
	q1->f(); q2->f();
	cout << "q1=" << q1 << endl;
	q1->g();
	memcpy(q2, q1, 8);
	q2->f();			//�����q1,ָ���C��
	delete p;
	delete q1; delete q2;

	int aaaa;
	cin >> aaaa;
}

/**********************************
��һ��û�м̳��ǵ����н��
D:\VCpp\�麯������\Debug>�麯������.ex
8
8
16		�����ֻ�Ƕ���һ��ָ�밡
16
************************************
�ڶ���ʹ�ü̳к�����
D:\VCpp\�麯������\Debug>�麯������.exe
8
16---->����8���ֽڣ���Ϊ�̳���һ��float
16
24---->����8���ֽڣ������һ��ָ�룬���ָ��ָ��һ�����飬
	�������ָ��ָ���麯�������ָ�루�麯����ָ�룩ָ���麯�����麯����������������
	�����麯���ĵ�ַ��Ҳ����˵��������ֻ��һ���麯����
*************************************
D:\VCpp\�麯������\Debug>�麯������.exe
C����麯��
D����麯��   //��ʵ�Ǹ������ָ��ȥһ�����ҵ�
*/