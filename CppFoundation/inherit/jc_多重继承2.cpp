#include <iostream>
#include <string>

using namespace std;

/*
解决了上个代码中遇到的问题

*/

class Goods {
	double price;
public:
	Goods(double p=123.45) :price(p) {
		cout << "Goods(" << p << ")" << endl;
	}
	~Goods() { cout << "~Goods()" << endl; }
	double getPrice() { return price; }
};

class Camera :virtual public Goods{
public:
	void take(const char *obj) {
		cout << "给" << obj << "照相" << endl;
	}
	Camera(double p) :Goods(p) { cout << "Camera()" << endl; }
	~Camera() { cout << "~Camera()" << endl; }
};

class MP3 :virtual public Goods {
public:
	void play(const char *song) {
		cout << "播放歌曲《" << song << "》" << endl;
	}
	MP3(double p) :Goods(p) { cout << "MP3()" << endl; }
	~MP3() { cout << "~MP3()" << endl; }
};

class Phone :virtual public Goods {
public:
	void dial(const char *no) {
		cout << "给" << no << "拨打电话" << endl;
	}
	Phone(double p) :Goods(p) { cout << "Phone()" << endl; }
	~Phone() { cout << "~Phone()" << endl; }
};

class ModernPhone : public Phone, public Camera, public MP3 {
	string factory;
public:
	void visitnet(const char *url) {
		cout << "访问网址" << url << endl;
	}
	ModernPhone(const char *factory, double price)    //虚继承：虚基类构造函数的参数由底层子类直接传递
		:MP3(price - 10), Phone(price - 20),			//来自下层子类中，合并保存一份
		Camera(price - 30), factory(factory), Goods(price){
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
	cout << mp.getPrice() << endl;			//还是有歧义，会出现错误，这个时候需要虚继承 

	int aaaa;
	cin >> aaaa;
}