#include <iostream>
#include <string>

using namespace std;
/*
���麯������ʵ����interface��C++ʵ��
���캯�����������麯������Ϊ���캯������Ҫ�Զ�����ʶ��
���������������Ǵ��麯������Ϊ��������һ�������
*/

class Animal {
public:
	Animal() { }				//���캯�����ܰ������麯��
	virtual ~Animal() {  }		//����Ҳ������
	void play() {			
		eat();				
		shout();	
		sleep();
	}
		
	virtual void eat() = 0;		//���麯��������interface��û�к�����
	virtual void shout() = 0;	//+ ��α�֤���麯��������ִ�У���������������Ķ���
	virtual void sleep() = 0;	//++ �������ó������ָ��ȥ�����������
};

class Horse :public Animal {
public:
	Horse() { cout << "@+_+!!!" << endl; }
	~Horse() { cout << "si ��@+_+!!!" << endl; }
	virtual void eat() { cout << "��Բ�" << endl; }
	virtual void shout() { cout << "��˻" << endl; }
	virtual void sleep() { cout << "վ��˯��" << endl; }
};

class Tiger :public Animal {
public:
	Tiger() { cout << "�ϻ�" << endl; }
	~Tiger() { cout << "si�ϻ�" << endl; }

	virtual void eat() { cout << "�ϻ�����" << endl; }
	virtual void shout() { cout << "��Х" << endl; }
	virtual void sleep() { cout << "ſ��˯��" << endl; }
};

int main() {
	Animal* p = NULL;
	char choice;
	cout << "h --��, t--�ϻ�����ѡ��";
	cin >> choice;
	if (choice == 'h')
		p = new Horse;
	else
		p = new Tiger;
	p->play();			//������������麯���������������ȷ���麯����ʵ���ϻ��ǵ��õ���Щ�麯��
	delete p;			//���ʱ���ͷŵ�ʱ�򣬻��ǵ��õĸ�����������������Ҫִ�����࣬����Ҫʹ���麯��
	//��ʱ��������������ɣ�������ִ�и���Ĺ���
	//int aaaa;
	//cin >> aaaa;
}
