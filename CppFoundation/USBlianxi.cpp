#include <iostream>
#include <string>
using namespace std;

class USB{
public:
	virtual void plugin() { cout << "plugin ..." << endl; }
	virtual void work() { cout << "I'm usb ..." << endl; }
	virtual void stop() { cout << "stop usb..." << endl; }
};

class USBDisk:public USB {
	void plugin() { cout << "USB plugin..." << endl; }
	void work() { cout << "I am usb disk.." << endl; }
	void stop() { cout << "USB is stop..." << endl; }
};

class USBFeng : public USB {
	void plugin() { cout << "Feng Shan plugin..." << endl; }
	void work() { cout << "I am  USB FengShan.." << endl; }
	void stop() { cout << "Feng Shan is stop..." << endl; }
};

class Computer{
public:
	void use(USB *p) {
		p->plugin();
		p->work();
		p->stop();
	}
};
int main() {
	USBDisk d;
	USBFeng f;
	Computer c;
	c.use(&d);		//USBDisk * 多态--->USB *p
					// 地址--> USB对象地址
					//实际上-->
	c.use(&f);

	int aaaa;
	cin >> aaaa;
}