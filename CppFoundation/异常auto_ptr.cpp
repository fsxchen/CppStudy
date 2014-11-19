#include <iostream>
using namespace std;
class A{
public:
	A() { cout << "A()" << this << endl; }
	~A() { cout << "~A()" << this << endl; }
};

class B{
public:
	B() { cout << "B()" << this << endl; }
	~B() { cout << "~B()" << this << endl; }
};
class D{
public:
	D() { cout << "D()" << this << endl; }
	~D() { cout << "~D()" << this << endl; }
};

class C {
	//D* p;
	auto_ptr<D> p;
public:
	C(int n) {
		//p = new D[3];
		auto_ptr<D> p(new D);
		//...
		//if(...) throw 
		//...
		if (n < 0) throw 888;
	}
	~C() {
		delete[] p;
	}
};

int main() {
	try {
		//A* p = new A;    
		auto_ptr<A> p(new A);    //�Զ�ָ�룬�쳣����ʱ��Ҳ���Զ�����
		B* q(new B);				//�쳣������ʱ�򣬲������
		C oc(-3);
		int n;
		cin >> n;
		if (n < 0)
			throw 123;
		cout << "n=" << n << endl;
		delete q;
	}
	catch (int e) {
		cout << "exception: " << e << endl;
	}

	
}