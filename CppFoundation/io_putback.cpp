#include <iostream>
#include <string>

using namespace std;
//i.putback(string)  退回去
//i.peek()  先看

int main() {
	char buf[100];
	char c = cin.get();
	cin.putback(c);		//退回去刚刚读到的字符
	if (isdigit(c)) {
		double d;
		cin >> d;
		cout << "d=" << d << endl;
	}
	else {
		string s;
		cin >> s;
		cout << "s=" << s << endl;
	}
	cin >> ws;			//跳过空白的字符
	cin.peek();			//只看，不会拿出缓冲区
	if(cin.peek() >= '0' && cin.peek() <= '9') {
		double d;
		cin >> d;
		cout << "d=" << d << endl;
	}
	else {
		string s;
		cin >> s;
		cout << "s=" << s << endl;
	}
}

/*
因为调用了get(),所以已经都出去了一个字符，这个时候，就需要putback
D:\VCpp
1234
d=234
*/