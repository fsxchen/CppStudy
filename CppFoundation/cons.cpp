#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	bool gender;
	int age;
	Person * p;

public:
	Person(const char * na, int a, bool g);
	void growup(int a);
	void show();
};

void Person::growup(int a) {
	age += a;
}

void Person::show() {
	cout << "�ҽ�" << this->name << "�Ա�" << (gender ?"��":"Ů")<< endl;
}
Person::Person(const char* name, int a, bool g) {
	cout << "A people is init" << endl;
	this->name = name;
	(*this).age = a;
	gender = g;
}

int main() {
	Person p("����", 18, true);
	p.show();

	Person q("����", 18, false);
	q.show();
	int a;
	cin >> a;
	return 0;
}