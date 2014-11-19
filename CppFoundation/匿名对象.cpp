#include <iostream>
#include <string>
using namespace std;
class Teacher{
	string name;
	string course;
public:
	Teacher(const char *n, const char* c) :name(n), course(c){
		cout << "创建" << course << "老师" << name << endl;
	}
	Teacher(const Teacher& t) :name(t.name), course(t.course){
		cout << "复制" << course << "老师" << name << endl;
	}
	~Teacher() {
		cout << "辞退" << course << "老师" << name << endl;
	}
	
};

int main() {
	Teacher t1("张三", "C++");
	Teacher t2 = t1;            //这个变量使用的是临时变量初始化，编译器会优化
	Teacher t3 = Teacher("李四", "UC");
	int a;
	cin >> a;
}