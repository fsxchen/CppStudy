#include <iostream>
#include <string>

using namespace std;

/*
一个构造函数，总是会先执行父类的构造函数，多个父类构造函数，按照继承的顺序执行
构造函数

*/
class Camera{
	double price;
public:
	void take(const char *obj) {
		cout << "给" << obj << "照相" << endl;
	}
	Camera(double p):price(p) { cout << "Camera()" << endl; }  //Camera的构造函数
	~Camera() { cout << "~Camera()" << endl; }
	double getPrice() { return price; }

};

class MP3 {
	double price;
public:
	void play(const char *song) {
		cout << "播放歌曲《" << song << "》" << endl;
	}
	MP3(double p, const char *banner):price(p) { cout << "MP3()" << endl; }			//MP3的构造方法
	~MP3() { cout << "~MP3()" << endl; }
	double getPrice() { return price; }
};

class Phone {											
	double price;
public:
	void dial(const char *no) {
		cout << "给" << no << "拨打电话" << endl;
	}
	Phone(double p):price(p) { cout << "Phone()" << endl; }		//电话的构造方法
	~Phone() { cout << "~Phone()" << endl; }
	double getPrice() { return price; }
};

class ModernPhone : public Phone, public Camera, public MP3 {	//现代的电话，继承了Phone，Camera，MP3
	string factory;
public:
	void visitnet(const char *url) {
		cout << "访问网址" << url << endl;
	}
	ModernPhone(const char *factory, double price):MP3(price, "sony"), Phone(price), Camera(price), factory(factory) {
																//这个ModernPhone也有个构造方法。但是，在实例化的时候，会
																//+根据继承的顺序来运行所有父类的构造方法，在实例化的时候执行构造的时候，
																//+必须将父类所需要的参数传递。也就是说，所有的父类都要传递初始化的参数
		cout << "ModernPhone()" << endl;
	}
	~ModernPhone() { cout << "~ModernPhone()" << endl; }
};

int main() {
	ModernPhone mp("nokia", 500);
	mp.dial("96166");
	mp.play("十年");
	mp.visitnet("bbs.tarena.com.cn");
	mp.take("赵云");
	//cout << mp.getPrice() << endl;							//由于父类都拥有getPrice的方法，所以这里会有歧义
	cout << mp.Phone::getPrice() << endl;						//解决思路，使用单独的类来处理价格，然后使用虚继承

	int aaaa;
	cin >> aaaa;
}