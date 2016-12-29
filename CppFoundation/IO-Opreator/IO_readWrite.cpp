#include <iostream>
#include <fstream>
using namespace std;

void encode(char *buf, int bytes) {
	for (int i = 0; i < bytes; i++)
		++*buf++;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << argv[0] << " 源文件" " 新文件" << endl;
		return 0;
	}

	ifstream f1(argv[1],ios::binary | ios::in);
	if (!f1) {
		cout << "打开" << argv[1] << "文件失败" << endl;
		return 1;
	}
	ofstream f2(argv[2], ios::binary | ios::out);
	if (!f2) {
		cout << "打开" << argv[2] << "文件失败" << endl;
		return 1;
	}
	char buf[100];
	while (f1) {
		f1.read(buf, sizeof(buf));	//不会关心buf的数据类型，但是要转成char *
									//+如果不是需要强转
		cout.write(buf, f1.gcount());
		encode(buf, sizeof(buf));
		f2.write(buf, f1.gcount());  //不要使用sizeof(buf)
	}
	f1.close();
	f2.close();
}