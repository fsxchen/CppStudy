#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	void play() {			//���ģʽ��ģ�巽�������˾��ø�������ӿڵĸ��
		eat();				//�ڹ��캯�������������е����麯���������ж�̬����Ϊ���๹��ִ��ʱ������Ĺ��컹û��ִ��
		shout();			//+����ڹ��캯���У�û�ж�̬
		sleep();
	}
	Animal() { sleep(); }		//������û�ж�̬��
	virtual ~Animal() { shout(); }		//�����ǿ���ʹ�ö�̬��
	virtual void eat() {}
	virtual void shout() { cout << "��" << endl; }
	virtual void sleep() { cout << "˯" << endl; }
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

/*
h --��, t--�ϻ�����ѡ��t
˯
�ϻ�
�ϻ�����
��Х
ſ��˯��
��
/**** ����ǰѹ��캯�����ó��麯����
D:\VCpp\��̬2\Debug>��̬2.exe
h --��, t--�ϻ�����ѡ��t
˯
�ϻ�
�ϻ�����
��Х
ſ��˯��
si�ϻ�
��
*/