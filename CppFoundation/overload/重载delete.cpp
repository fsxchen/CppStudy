#include <iostream>
#include <string>

using namespace std;
char mem[1000];
int pos;

class A {			//任何一个类，至少占用一个字节
public:
	A() { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
	static void* operator new[](size_t bytes){  //new 的重载,即使不写，也是存在这个static
		cout << "size is" << bytes << endl;   //输出的是7，？ new一个数组的时候，会额外的分配4个字节，来保存数组的长度
		cout << "new A" << endl;				//+析构可以依赖这个长度来delete数据
		int alloc = pos;
		pos += bytes;
		return mem + alloc;
	
	}   
	void operator delete[](void* p) {				//static
		cout << "delete A" << endl; 
		
	}			

};

int main() {
	A *x = new A;		//1、分配空间 2、执行构造函数
	delete x;			//1、执行析构函数 2、释放空间

	x = new A[3];		//如果是数组，会带一个[]
	delete[] x;

	int ma;
	cin >> ma;
}

