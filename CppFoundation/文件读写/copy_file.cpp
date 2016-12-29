/*
 *
 *复制文件
 *
 *
 * */
#include <string>
#include <fstream>

using namespace std;

int main() {
	ifstream in("copy_file.cpp");	//打开一个可读的文件。
	ofstream out("/tmp/copy_file.cpp");	//打开一个等待写的文件

	string s;
	while(getline(in, s))
		out << s << "\n";
}


/*
 *getline读取一行，分隔符默认为回车，可以修改
 * */
