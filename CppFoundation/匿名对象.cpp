#include <iostream>
#include <string>
using namespace std;
class Teacher{
	string name;
	string course;
public:
	Teacher(const char *n, const char* c) :name(n), course(c){
		cout << "����" << course << "��ʦ" << name << endl;
	}
	Teacher(const Teacher& t) :name(t.name), course(t.course){
		cout << "����" << course << "��ʦ" << name << endl;
	}
	~Teacher() {
		cout << "����" << course << "��ʦ" << name << endl;
	}
	
};

int main() {
	Teacher t1("����", "C++");
	Teacher t2 = t1;            //�������ʹ�õ�����ʱ������ʼ�������������Ż�
	Teacher t3 = Teacher("����", "UC");
	int a;
	cin >> a;
}