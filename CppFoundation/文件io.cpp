#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	string path = "D:\\VCpp_foundation\\文件io\\文件io\\文件io.cpp";
	ifstream fin(path);		//这里只接受c风格字符串,vs2013好像可以是string
	/*
	ifstream fin;
	fin.open(path);
	*/
	ofstream fout("文件io_copy.cpp");
	if (!fin) {
		cout << "打开文件 " << path << " 失败" << endl;
		return 1;
	}
	if (!fout) {
		cout << "打开文件失败" << endl;
		return 2;
	}
	char ch;
	fin.get();
	//while (fin >> ch) cout << ch;		//发现这样子的没有空格(\n \r 空格),会跳过所有的空白
	//while ((ch = fin.get()) != EOF) cout << ch; //等价于下面的
	//while (fin.get(ch)) {
	//	cout << ch; fout << ch;
	//}
	while (fin) { fin.get(ch); fout << ch; }  //这样和上面会多写最后一个字符，最后的字符会多写一个\n
												//这个是一个逻辑问题
	//fin.getline();
	fin.close();
	fout.close();
	int aaaa;
	cin >> aaaa;
}