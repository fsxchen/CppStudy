#include <iostream>
#include <string>
#include <cstring>   //C里面的string.h
using namespace std;

class A {
public:
	typedef unsigned int uint;   //在类的内部定义的，如果在外部使用，则需要A::uint。类的内部类型
private:
	int * p;
	uint n;
public:
	
	A(uint n) :n(n){ p = new int[n]; if (p == NULL) throw 0; }
	~A() { delete[] p; }
	uint size() const { return n; }
	int& operator[](uint i) const{ if (i >= n) throw 1; return p[i]; }
	int& operator[](char* c) const{				//方括号重载
		int i = atoi(c);
		if (i < 0 || i >= n) throw 1;
		return p[i];
	}
	void operator() (int v) { for (int i = 0; i < n; i++) p[i] = v; }
	void operator() (const char* s) {			//圆括号重载
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
	x(3);   //x.operator()(3)		//圆括号重载
	y("50");
	cout << "x=" << x << ", y=" << y << endl;
	//x[5];								//数组下标越界
	cout << x(10, 2) << endl;    //x.operator()(10, 2)重载是有两个变量，()的重载很灵活
	cout << "我是分割线" << endl;
	cout << "x=" << x << ", y=" << y << endl;
	int aaa;
	cin >> aaa;
}