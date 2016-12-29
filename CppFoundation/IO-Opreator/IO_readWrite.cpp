#include <iostream>
#include <fstream>
using namespace std;

void encode(char *buf, int bytes) {
	for (int i = 0; i < bytes; i++)
		++*buf++;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << argv[0] << " Դ�ļ�" " ���ļ�" << endl;
		return 0;
	}

	ifstream f1(argv[1],ios::binary | ios::in);
	if (!f1) {
		cout << "��" << argv[1] << "�ļ�ʧ��" << endl;
		return 1;
	}
	ofstream f2(argv[2], ios::binary | ios::out);
	if (!f2) {
		cout << "��" << argv[2] << "�ļ�ʧ��" << endl;
		return 1;
	}
	char buf[100];
	while (f1) {
		f1.read(buf, sizeof(buf));	//�������buf���������ͣ�����Ҫת��char *
									//+���������Ҫǿת
		cout.write(buf, f1.gcount());
		encode(buf, sizeof(buf));
		f2.write(buf, f1.gcount());  //��Ҫʹ��sizeof(buf)
	}
	f1.close();
	f2.close();
}