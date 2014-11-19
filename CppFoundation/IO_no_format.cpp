#include <iostream>
#include <string>

using namespace std;
/*
i.get()
o.put()
i.getline(),读取一行输入，知道换行为止
i.ignore(),忽略
i.pubback(),回退
i.peek(),预先探测一个字符
*/
int main() {
	int n = cin.get();  //返回读到的ascii, int get()
	char c, d, e;
	cin.get(c).get(d).get(e);			//istream& get(char& ch)
	cout << n << ',' << c << ',' << d << ',' << e << endl;
	cout.put(n).put(c).put(d).put(e);

	char ch;
	cin.ignore(200, '\n');	//忽略，抛弃一个缓冲区字符，arg1:最多抛弃几个字符，默认是1
							//arg2:抛到哪个字符为止，默认是文件末尾，经常用来清空输入缓冲区
							
	cin >> ch;		//如果没有上面的清楚操作，那么直接冲输入缓存区读取
	cout << "ch=" << ch << endl;
	int aaaa;
	cin >> aaaa;
}