#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	cout.width(10);
	cout << 123 << ',' << 123 << endl;  //只对前面的有效
	cout.width(2);
	cout << 123 << ',' << 123 << endl;	//指定的最大宽度，如果超过了，。

	cout << setw(10) << 123 << ',' << hex<< 123 << endl;	//格式控制符，类似于hex这类,
															//+没有参数,一旦指定，后面全部生效
															//带参数的需要一个头文件iomanip
	cout.setf(ios::hex, ios::basefield);//oct, dec, showbase)				//可以设置的格式标志
												//进制域里面只能使用16进制

	cout.setf(ios::hex, ios::basefield);	//使用格式控制符，会比较简单
	cout << showbase << 123 << endl;
	cout.unsetf(ios::hex);
	cout << 123 << endl;
	
	cout << 5.0 << endl;
	cout << showpoint << 5.0 << endl;		//总是显示小数点,有效数字保留6位
											//scientific  科学计数法
	//cout << scientific << 5.0 << endl;

	cout.precision(3);
	cout << 95.0 << endl;//指定精度 输出95.0  输出的是3个有效的

	cout << fixed << 95.0 << endl;		//表示。小数点后面的有效位数
	cout << setprecision(2) << 800.0 << endl;		//使用格式控制符
	cout << showpos << 123 << ',' << 45.6 << endl;	//给正数带上＋
	cout << uppercase << hex << 123 << ", " << scientific << 95.0 << endl;		//16进制、科学计数法大写
	//宽度与对齐的问题
	cout << dec << setw(10) << 123 << endl;		//默认是右对齐
	cout << left << setw(10) << 123 << endl;	//左对齐
	//指定填充字符
	cout.fill('#');
	cout << dec << setw(10) << 123 << endl;		//默认是右对齐
	cout << left << setw(10) << 123 << endl;	//左对齐
	cout << setfill('*') << left<< setw(10) << 123 << endl;
	cout << internal << setw(10) << 234 << endl;  //对齐
	cout << right << setw(10) << 234 << endl;
	
	/*

	long long int t = 0x1234567887654321;
	//      0xffff0000
	//0xffffffff
	int a, b;
	char *c;
	

	for (int i = 0; i < 8; i++) {
		c = (char *)&t;
		cout << hex << int(*c) << endl;
		t = t >> 8;
		//cout << hex << t << endl;
	}
	
	*/
	int aaaa;
	cin >> aaaa;
}