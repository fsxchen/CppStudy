#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	bool gender;
public:
	void eat(const char *food) { cout << name << "在吃" << food << endl; }
	void sleep();
	void show() {
		cout << "大家好， 我是" << (gender ? "帅哥" : "美女") << name << "，很荣幸认识你" << endl;
	}
	Person(const char *name, bool gender):name(name), gender(gender) {}
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
	void show(const char *_class) {						//重写，即使是不同的参数表，父类的也会被隐藏，
														//+如果调用时是不会重载的，即在Teacher实例中调用无参的show，会报错
														//+此时还是可以调用父类的show,可以使用Person::show()
		cout << "同学们好， 我是" << course << "老师" << 
			Name() << "， 希望能带领大家把" << course << "课程学好" << endl;
	}
};
int main() {
	Person a("大乔", false);
	Teacher b("张飞", true, "UNIX C");
	a.eat("巧克力");
	b.eat("泡椒凤爪");
	a.show();
	b.show();
	b.teach("csd1007");
	int aaaa;
	cin >> aaaa;
}