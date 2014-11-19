#include <iostream>
#include <string>


//.getline(char 数组, 数组大小), 如果没有读取一整行，也会有io错误。
//getline(i对象, string对象引用， 读到某个字符为止 默认是回车)
//+这个 比较好用，这个不是成员函数，
//是一个全局函数，在string里面
// s.c_str()  将c++风格字符串转化为c风格字符串

// 都可以加上第三个参数，读到某个参数为止

using namespace std;

int main() {
	char buf[10];
	if (!cin.getline(buf, sizeof(buf))) {
		cout << "错误：行超长\n";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	string s;
	getline(cin, s);
	
	cout << "buf=[" << buf << "]\n";
	cout << "s=[" << s << "]\n";
	int aaaa;
	cin >> aaaa;
}