#include <iostream>
#include <string>
using namespace std;
/*
需要在linux下面运行，格式化输出
输出缓冲区遇到换行，有输入，满，程序结束，flush会刷新
*/
int main() {
	cout << "hello";		//缓冲，可重定向
	cerr << "World";		//无缓冲，不可重定向
	clog << "TTTT";			//理论上缓冲，不可重定向，实际和cerr一样，无缓冲，不可。。。
	//int aaaa; 
	//cin >> aaaa;
}