#include <iostream>
#include <string>
#include <cstring>   //C�����string.h
using namespace std;

class A {
public:
	typedef unsigned int uint;   //������ڲ�����ģ�������ⲿʹ�ã�����ҪA::uint������ڲ�����
private:
	int * p;
	uint n;
public:
	
	A(uint n) :n(n){ p = new int[n]; if (p == NULL) throw 0; }
	~A() { delete[] p; }
	uint size() const { return n; }
	int& operator[](uint i) const{ if (i >= n) throw 1; return p[i]; }
	int& operator[](char* c) const{				//����������
		int i = atoi(c);
		if (i < 0 || i >= n) throw 1;
		return p[i];
	}
	void operator() (int v) { for (int i = 0; i < n; i++) p[i] = v; }
	void operator() (const char* s) {			//Բ��������
		int v = atoi(s);
		for (uint i = 0; i < n; i++) p[i] += v;
	}
	int operator() (int beg, int delta) {
		for (uint i = 0; i < n; i++) p[i] = beg, beg += delta;
		return p[n - 1];
	}
};

ostream& operator<<(ostream& o, const A& a) {
	o << "{";
	for (A::uint i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << "}";
	return o;
}
int main() {
	A x(5), y(8);
	x[2] = 20; y[6] = 66;	//x.operator[](uint); y.operator[6]
	x["2"] = 3; y["2"] = 8;
	x(3);   //x.operator()(3)		//Բ��������
	y("50");
	cout << "x=" << x << ", y=" << y << endl;
	//x[5];								//�����±�Խ��
	cout << x(10, 2) << endl;    //x.operator()(10, 2)������������������()�����غ����
	cout << "���Ƿָ���" << endl;
	cout << "x=" << x << ", y=" << y << endl;
	int aaa;
	cin >> aaa;
}