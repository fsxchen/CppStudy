#include <iostream>
#include <string>

using namespace std;

struct date {
	int year;
	int month;
	int day;
};

struct Person {			//C++�нṹ�����࣬����Ĭ�ϵķ���Ȩ�޲�һ��
						//+�ṹ��Ĭ��Ȩ����public
	string name;
	int age;
	bool gender;
	double salary;
	date birth;
	Person() { cout << "����Person������" << this << endl; }
	~Person() { cout << "�ͷ�Person������" << this << endl; }
};

//����ģʽ�����캯��д��˽�е�

class autoptr {
	Person *p;
	static int cnt;								//���ж�����һ��һ��cnt����
public:
	autoptr(Person* p) :p(p) { ++cnt; }
	autoptr(const autoptr& a) :p(a.p) { ++cnt; }
	~autoptr() { if(--cnt == 0) delete p; }
	Person * operator->() { return p; }		//����->���÷�,������������ָ�룬�Ƚ�Σ��
											//����ʹ�ü����������
	Person& operator*() { return *p; }
};

int autoptr::cnt = 0;		//��̬��Ա�ĳ�ʼ����Ҫ��������
int main() {
	// autoptr a = new Person;
	Person* a = new Person;   //a.cnt == 
	autoptr b = new Person;	  //b.cnt == 
	autoptr c = b;			  //c.cnt == 		//�ᷢ���ظ��ͷţ��ڳ�ʼ����ʱ�򣬻��b�ĵ�ַ��c��
	autoptr d = b;								//+�ڽ�����ʱ�򣬻��ٴ��ͷ�bָ��ĵ�ַ
	b->name = "�ŷ�";
	cout << b->age <<endl;
	cout << (*b).name << endl;
	int in;
	cin >> in;
}