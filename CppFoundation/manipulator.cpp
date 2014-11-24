#include <iostream>
using namespace std;
//自己制作的输出格式控制符
//自定义的格式控制符

class __HEXUB {           //无参数的格式控制符号
	friend ostream& operator<<(ostream& o, const __HEXUB& h) {
		return o << hex << uppercase << showbase;
	}
};
const __HEXUB hexub = __HEXUB();

//无参数的格式控制符也可是函数
ostream& func(ostream& o){
	return o << dec << showpos;
}

//带参数的，可以是类，也可以是对象或者函数
class wf{
	unsigned int w;
	char f;
public:
	wf(unsigned int w, char fill=' '):w(w), f(fill) {}
	friend ostream& operator<<(ostream& o, const wf& x){
		o.width(x.w);
		o.fill(x.f);
		return o;
	}
	
};
int main() {
	cout << hexub << 123 << endl; //0X7B，这里会去使用__HEXHB类里面的方法。
	cout << wf(10, '*') << "good" << endl;
	cout << wf(8) << "good" << endl;
	cout << func << 123 << endl;
}
