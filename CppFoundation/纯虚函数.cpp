#include <iostream>
#include <string>

using namespace std;
/*
纯虚函数，其实就是interface的C++实现
构造函数不可用是虚函数，因为构造函数不需要自动类型识别
析构函数不可以是纯虚函数，因为析构函数一定会调用
*/

class Animal {
public:
	Animal() { }				//构造函数不能包含纯虚函数
	virtual ~Animal() {  }		//析构也不能有
	void play() {			
		eat();				
		shout();	
		sleep();
	}
		
	virtual void eat() = 0;		//纯虚函数，类似interface，没有函数体
	virtual void shout() = 0;	//+ 如何保证纯虚函数本身不被执行，不允许创建抽象类的对象
	virtual void sleep() = 0;	//++ 但可以用抽象类的指针去引用子类对象
};

class Horse :public Animal {
public:
	Horse() { cout << "@+_+!!!" << endl; }
	~Horse() { cout << "si 马@+_+!!!" << endl; }
	virtual void eat() { cout << "马吃草" << endl; }
	virtual void shout() { cout << "马嘶" << endl; }
	virtual void sleep() { cout << "站着睡觉" << endl; }
};

class Tiger :public Animal {
public:
	Tiger() { cout << "老虎" << endl; }
	~Tiger() { cout << "si老虎" << endl; }

	virtual void eat() { cout << "老虎吃肉" << endl; }
	virtual void shout() { cout << "虎啸" << endl; }
	virtual void sleep() { cout << "趴着睡觉" << endl; }
};

int main() {
	Animal* p = NULL;
	char choice;
	cout << "h --马, t--老虎，请选择：";
	cin >> choice;
	if (choice == 'h')
		p = new Horse;
	else
		p = new Tiger;
	p->play();			//这个函数不是虚函数，但是它里面的确是虚函数，实际上还是调用的那些虚函数
	delete p;			//这个时候，释放的时候，还是调用的父类的析构函数，如果要执行子类，则需要使用虚函数
	//此时如果子类的析构完成，还会再执行父类的构造
	//int aaaa;
	//cin >> aaaa;
}
