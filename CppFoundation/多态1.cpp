#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	bool gender;
public:
	void eat(const char *food) { cout << name << "�ڳ�" << food << endl; }
	void sleep();
	virtual void show() {             //�麯�����������������ʱ�򣬻���ݶ�������������,�����Զ�ʵ�ֶ�̬����java��һ��
		cout << "��Һã� ����" << (gender ? "˧��" : "��Ů") << name << "����������ʶ��" << endl;
	}
	Person(const char *name, bool gender) :name(name), gender(gender) {}
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
	void show() {																		
		cout << "ͬѧ�Ǻã� ����" << course << "��ʦ" <<
			Name() << "�� ϣ���ܴ����Ұ�" << course << "�γ�ѧ��" << endl;
	}
};
int main() {
	Person a("����", false);
	Teacher b("���", true, "Unix C");
	Person c = b;
	Person& d = b;

	Person *p = NULL, *q = NULL;
	p = &a;
	q = &b;
	p->show();
	q->show();
	c.show();	//�����ݶ������ͣ������ø��Ե�show�������Ǹ���ָ������ͣ���ô��Ҫ�麯��
	d.show();					//ֻ��ͨ��ָ������麯����ʱ�򣬲Ż��ж�̬�������ľͲ����ˡ�������Ҳ�ǿ��Եģ�
	cout << dynamic_cast<Teacher*>(p) << endl;			//dynamic_cast()Ҫ���������麯��������ʶ��
	cout << dynamic_cast<Teacher*>(q) << endl;
	cout << dynamic_cast<Teacher*>(&c) << endl;
	cout << dynamic_cast<Teacher*>(&d) << endl;

	int aaaa;
	cin >> aaaa;
}