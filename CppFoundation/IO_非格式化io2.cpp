#include <iostream>
#include <string>
using namespace std;

ostream& operator<<(ostream& os, istream& c) {
	cout << c;
	return os;
}
ostream& operator<<(ostream &os, ostream o) {
	return os;
}

//io对象要求能转换成bool类型，对于正常状态的io对象转成true，
//对于错误状态的io转成false
//可以用来判断输入和输出是否正确的执行了
//io对象一旦处于错误状态，就拒绝读写了，如何继续工作？？
//cin.clear()   cout.clear() 注意哦：不会清除缓冲区，只会清除错误状态
//.eof()，是否超过文件末尾
//.fail(),是否失败.bad()   ,.good()

int main() {
	cout << cin << endl;
	//cout << cout << endl;

	int n;
	cin >> n;
	cout << cin << endl;
	int aaaa;
	cin >> aaaa;
	cout << cin;
	cout << &cin << endl;
	cout << &cout << endl;
}