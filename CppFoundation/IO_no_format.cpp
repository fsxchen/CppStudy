#include <iostream>
#include <string>

using namespace std;
/*
i.get()
o.put()
i.getline(),��ȡһ�����룬֪������Ϊֹ
i.ignore(),����
i.pubback(),����
i.peek(),Ԥ��̽��һ���ַ�
*/
int main() {
	int n = cin.get();  //���ض�����ascii, int get()
	char c, d, e;
	cin.get(c).get(d).get(e);			//istream& get(char& ch)
	cout << n << ',' << c << ',' << d << ',' << e << endl;
	cout.put(n).put(c).put(d).put(e);

	char ch;
	cin.ignore(200, '\n');	//���ԣ�����һ���������ַ���arg1:������������ַ���Ĭ����1
							//arg2:�׵��ĸ��ַ�Ϊֹ��Ĭ�����ļ�ĩβ����������������뻺����
							
	cin >> ch;		//���û������������������ôֱ�ӳ����뻺������ȡ
	cout << "ch=" << ch << endl;
	int aaaa;
	cin >> aaaa;
}