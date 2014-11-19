#include <iostream>
#include <string>

using namespace std;

/*
һ�����캯�������ǻ���ִ�и���Ĺ��캯����������๹�캯�������ռ̳е�˳��ִ��
���캯��

*/
class Camera{
	double price;
public:
	void take(const char *obj) {
		cout << "��" << obj << "����" << endl;
	}
	Camera(double p):price(p) { cout << "Camera()" << endl; }  //Camera�Ĺ��캯��
	~Camera() { cout << "~Camera()" << endl; }
	double getPrice() { return price; }

};

class MP3 {
	double price;
public:
	void play(const char *song) {
		cout << "���Ÿ�����" << song << "��" << endl;
	}
	MP3(double p, const char *banner):price(p) { cout << "MP3()" << endl; }			//MP3�Ĺ��췽��
	~MP3() { cout << "~MP3()" << endl; }
	double getPrice() { return price; }
};

class Phone {											
	double price;
public:
	void dial(const char *no) {
		cout << "��" << no << "����绰" << endl;
	}
	Phone(double p):price(p) { cout << "Phone()" << endl; }		//�绰�Ĺ��췽��
	~Phone() { cout << "~Phone()" << endl; }
	double getPrice() { return price; }
};

class ModernPhone : public Phone, public Camera, public MP3 {	//�ִ��ĵ绰���̳���Phone��Camera��MP3
	string factory;
public:
	void visitnet(const char *url) {
		cout << "������ַ" << url << endl;
	}
	ModernPhone(const char *factory, double price):MP3(price, "sony"), Phone(price), Camera(price), factory(factory) {
																//���ModernPhoneҲ�и����췽�������ǣ���ʵ������ʱ�򣬻�
																//+���ݼ̳е�˳�����������и���Ĺ��췽������ʵ������ʱ��ִ�й����ʱ��
																//+���뽫��������Ҫ�Ĳ������ݡ�Ҳ����˵�����еĸ��඼Ҫ���ݳ�ʼ���Ĳ���
		cout << "ModernPhone()" << endl;
	}
	~ModernPhone() { cout << "~ModernPhone()" << endl; }
};

int main() {
	ModernPhone mp("nokia", 500);
	mp.dial("96166");
	mp.play("ʮ��");
	mp.visitnet("bbs.tarena.com.cn");
	mp.take("����");
	//cout << mp.getPrice() << endl;							//���ڸ��඼ӵ��getPrice�ķ��������������������
	cout << mp.Phone::getPrice() << endl;						//���˼·��ʹ�õ�������������۸�Ȼ��ʹ����̳�

	int aaaa;
	cin >> aaaa;
}