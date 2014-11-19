#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	void play() {			//设计模式，模板方法，个人觉得更类似与接口的概念。
		eat();				//在构造函数和析构函数中调用虚函数，不会有多态。因为父类构造执行时，子类的构造还没有执行
		shout();			//+因此在构造函数中，没有多态
		sleep();
	}
	Animal() { sleep(); }		//这里是没有多态的
	virtual ~Animal() { shout(); }		//析构是可以使用多态的
	virtual void eat() {}
	virtual void shout() { cout << "叫" << endl; }
	virtual void sleep() { cout << "睡" << endl; }
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

/*
h --马, t--老虎，请选择：t
睡
老虎
老虎吃肉
虎啸
趴着睡觉
叫
/**** 这个是把构造函数设置成虚函数了
D:\VCpp\多态2\Debug>多态2.exe
h --马, t--老虎，请选择：t
睡
老虎
老虎吃肉
虎啸
趴着睡觉
si老虎
叫
*/