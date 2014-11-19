#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	bool gender;
public:
	void eat(const char *food) { cout << name << "�ڳ�" << food << endl; }
	void sleep();
	void show() {
		cout << "��Һã� ����" << (gender ? "˧��" : "��Ů") << name << "����������ʶ��" << endl;
	}
	Person(const char *name, bool gender):name(name), gender(gender) {}
	string Name()const { return name; }
};

class Teacher : public Person {			//C++�̳У������̳�
	string course;
public:
	void teach(const char *_class) {
		cout << Name() << "��ʦ�ڸ�" << _class << "�ི" << course << "�γ�" << endl;
	}
	Teacher(const char*name, bool gender, const char *course) :
		Person(name, gender), course(course){}			//ֻ���ڳ�ʼ���б�����������ʼ�����������
	void show(const char *_class) {						//��д����ʹ�ǲ�ͬ�Ĳ����������Ҳ�ᱻ���أ�
														//+�������ʱ�ǲ������صģ�����Teacherʵ���е����޲ε�show���ᱨ��
														//+��ʱ���ǿ��Ե��ø����show,����ʹ��Person::show()
		cout << "ͬѧ�Ǻã� ����" << course << "��ʦ" << 
			Name() << "�� ϣ���ܴ����Ұ�" << course << "�γ�ѧ��" << endl;
	}
};
int main() {
	Person a("����", false);
	Teacher b("�ŷ�", true, "UNIX C");
	a.eat("�ɿ���");
	b.eat("�ݽ���צ");
	a.show();
	b.show();
	b.teach("csd1007");
	int aaaa;
	cin >> aaaa;
}