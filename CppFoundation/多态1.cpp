#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	bool gender;
public:
	void eat(const char *food) { cout << name << "在吃" << food << endl; }
	void sleep();
	virtual void show() {             //虚函数，调用这个函数的时候，会根据对象类型来调用,不会自动实现多态，和java不一样
		cout << "大家好， 我是" << (gender ? "帅哥" : "美女") << name << "，很荣幸认识你" << endl;
	}
	Person(const char *name, bool gender) :name(name), gender(gender) {}
	string Name()const { return name; }
};

class Teacher : public Person {			//C++继承，公开继承
	string course;
public:
	void teach(const char *_class) {
		cout << Name() << "老师在给" << _class << "班讲" << course << "课程" << endl;
	}
	Teacher(const char*name, bool gender, const char *course) :
		Person(name, gender), course(course){}			//只能在初始化列表中这样来初始化父类的属性
	void show() {																		
		cout << "同学们好， 我是" << course << "老师" <<
			Name() << "， 希望能带领大家把" << course << "课程学好" << endl;
	}
};
int main() {
	Person a("大乔", false);
	Teacher b("诸葛", true, "Unix C");
	Person c = b;
	Person& d = b;

	Person *p = NULL, *q = NULL;
	p = &a;
	q = &b;
	p->show();
	q->show();
	c.show();	//？根据对象类型，来调用各自的show，而不是根据指针的类型，那么需要虚函数
	d.show();					//只有通过指针调用虚函数的时候，才会有多态。其他的就不行了。（引用也是可以的）
	cout << dynamic_cast<Teacher*>(p) << endl;			//dynamic_cast()要求父类中有虚函数，类型识别
	cout << dynamic_cast<Teacher*>(q) << endl;
	cout << dynamic_cast<Teacher*>(&c) << endl;
	cout << dynamic_cast<Teacher*>(&d) << endl;

	int aaaa;
	cin >> aaaa;
}