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

//io����Ҫ����ת����bool���ͣ���������״̬��io����ת��true��
//���ڴ���״̬��ioת��false
//���������ж����������Ƿ���ȷ��ִ����
//io����һ�����ڴ���״̬���;ܾ���д�ˣ���μ�����������
//cin.clear()   cout.clear() ע��Ŷ�����������������ֻ���������״̬
//.eof()���Ƿ񳬹��ļ�ĩβ
//.fail(),�Ƿ�ʧ��.bad()   ,.good()

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