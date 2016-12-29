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
	virtual void f() { cout << "C类的虚函数" << endl; }
	virtual void g() { cout << this << ", &d=" << &d << endl; }  //这两个地址之间就是虚拟指针的地址值
};

class D:public C {
	double d;
public:
	virtual void f() { cout << "D类的虚函数" << endl; }
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
	q2->f();			//输出是q1,指向的C类
	delete p;
	delete q1; delete q2;

	int aaaa;
	cin >> aaaa;
}

/**********************************
第一次没有继承是的运行结果
D:\VCpp\虚函数本质\Debug>虚函数本质.ex
8
8
16		这里就只是多了一个指针啊
16
************************************
第二次使用继承后的输出
D:\VCpp\虚函数本质\Debug>虚函数本质.exe
8
16---->多了8个字节，因为继承了一个float
16
24---->多了8个字节，这个是一个指针，这个指针指向一个数组，
	这个隐藏指针指向虚函数表，虚表指针（虚函数表指针）指向虚函数表，虚函数表里，存有这个类里
	所有虚函数的地址。也就是说，整个类只有一个虚函数表。
*************************************
D:\VCpp\虚函数本质\Debug>虚函数本质.exe
C类的虚函数
D类的虚函数   //其实是根据虚表指针去一层层查找的
*/