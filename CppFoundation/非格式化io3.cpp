#include <iostream>
#include <string>


//.getline(char ����, �����С), ���û�ж�ȡһ���У�Ҳ����io����
//getline(i����, string�������ã� ����ĳ���ַ�Ϊֹ Ĭ���ǻس�)
//+��� �ȽϺ��ã�������ǳ�Ա������
//��һ��ȫ�ֺ�������string����
// s.c_str()  ��c++����ַ���ת��Ϊc����ַ���

// �����Լ��ϵ���������������ĳ������Ϊֹ

using namespace std;

int main() {
	char buf[10];
	if (!cin.getline(buf, sizeof(buf))) {
		cout << "�����г���\n";
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