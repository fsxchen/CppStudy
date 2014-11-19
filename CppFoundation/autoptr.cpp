#include <iostream>
#include <string>

using namespace std;

struct date {
	int year;
	int month;
	int day;
};

struct Person {			//C++中结构和类差不多，除了默认的访问权限不一样
						//+结构的默认权限是public
	string name;
	int age;
	bool gender;
	double salary;
	date birth;
	Person() { cout << "创建Person对象在" << this << endl; }
	~Person() { cout << "释放Person对象在" << this << endl; }
};

//单例模式，构造函数写成私有的

class autoptr {
	Person *p;
	static int cnt;								//所有对象公用一个一个cnt属性
public:
	autoptr(Person* p) :p(p) { ++cnt; }
	autoptr(const autoptr& a) :p(a.p) { ++cnt; }
	~autoptr() { if(--cnt == 0) delete p; }
	Person * operator->() { return p; }		//重载->的用法,可以用来重载指针，比较危险
											//可以使用计数器来解决
	Person& operator*() { return *p; }
};

int autoptr::cnt = 0;		//静态成员的初始化，要放在外面
int main() {
	// autoptr a = new Person;
	Person* a = new Person;   //a.cnt == 
	autoptr b = new Person;	  //b.cnt == 
	autoptr c = b;			  //c.cnt == 		//会发生重复释放，在初始化的时候，会把b的地址给c，
	autoptr d = b;								//+在结束的时候，会再次释放b指向的地址
	b->name = "张飞";
	cout << b->age <<endl;
	cout << (*b).name << endl;
	int in;
	cin >> in;
}