#include <iostream>
#include <string>

using namespace std;
//i.putback(string)  �˻�ȥ
//i.peek()  �ȿ�

int main() {
	char buf[100];
	char c = cin.get();
	cin.putback(c);		//�˻�ȥ�ոն������ַ�
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
	cin >> ws;			//�����հ׵��ַ�
	cin.peek();			//ֻ���������ó�������
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
��Ϊ������get(),�����Ѿ�����ȥ��һ���ַ������ʱ�򣬾���Ҫputback
D:\VCpp
1234
d=234
*/