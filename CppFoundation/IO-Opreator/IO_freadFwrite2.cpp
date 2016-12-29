#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void encode(char *buf, int bytes) {
	for (int i = 0; i < bytes; i++)
		++*buf++;
}

void decode(char *buf, int bytes) {
	for (int i = 0; i < bytes; i++)
		--*buf++;
}

int main(int argc, char* argv[]) {
	if (argc != 3 || strcmp(argv[1], "-e") && strcmp(argv[1], "-d")) {
		cout << argv[0] << " -e | -d �ļ�" << endl;
		return 0;
	}

	fstream f1(argv[2], ios::binary | ios::in | ios::out);
	if (!f1) {
		cout << "��" << argv[1] << "�ļ�ʧ��" << endl;
		return 1;
	}
	
	char buf[100];
	void(*p)(char *, int) = argv[1][1] == 'e' ? encode : decode;
	int pos1 = 0, pos2 = 0, bytes;
	while (f1) {
		f1.seekg(pos1);
		f1.read(buf, sizeof(buf));	//�������buf���������ͣ�����Ҫת��char *
									//+���������Ҫǿת
		if (!f1) {
			f1.clear();
			break;
		}
		else
			pos2 = f1.tellg();
		bytes = f1.gcount();
		
		p(buf, f1.gcount());
		cout.write(buf, bytes);
		f1.seekp(pos1);		//f1.seekp(-bytes, ios::cur)
		
		f1.write(buf, f1.gcount());  //��Ҫʹ��sizeof(buf)
		pos1 = pos2;
	}
	f1.close();
}