#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	string path = "D:\\VCpp_foundation\\�ļ�io\\�ļ�io\\�ļ�io.cpp";
	ifstream fin(path);		//����ֻ����c����ַ���,vs2013���������string
	/*
	ifstream fin;
	fin.open(path);
	*/
	ofstream fout("�ļ�io_copy.cpp");
	if (!fin) {
		cout << "���ļ� " << path << " ʧ��" << endl;
		return 1;
	}
	if (!fout) {
		cout << "���ļ�ʧ��" << endl;
		return 2;
	}
	char ch;
	fin.get();
	//while (fin >> ch) cout << ch;		//���������ӵ�û�пո�(\n \r �ո�),���������еĿհ�
	//while ((ch = fin.get()) != EOF) cout << ch; //�ȼ��������
	//while (fin.get(ch)) {
	//	cout << ch; fout << ch;
	//}
	while (fin) { fin.get(ch); fout << ch; }  //������������д���һ���ַ��������ַ����дһ��\n
												//�����һ���߼�����
	//fin.getline();
	fin.close();
	fout.close();
	int aaaa;
	cin >> aaaa;
}