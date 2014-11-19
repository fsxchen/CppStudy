#include <iostream>
#include <string>
using namespace std;
typedef string T;

/*拷贝构造函数：当有指针成员指向了动态的元素，默认的拷贝构造函数，会复制原来的地址so：
1、重写拷贝构造函数
2、还有自己要重写赋值（=）函数，
3、还要写析构函数
*/
class Stack {
	typedef unsigned int uint;
	T* mem;
	uint max;
	uint len;
public:
	Stack(const Stack& s) :mem(new T[s.max]), max(s.max), len(s.len) {}			//拷贝构造函数
																				//+在这里解决了析构时多次释放内存的问题
															//+还可以使用引用计数，这里为每一个引用申请了一块新的空间
	Stack(unsigned int n) :mem(new T[n]), max(n), len(0) {}
	uint max_size()const{ return max; }
	uint size()const{ return len; }
	Stack& push(const T& e) { if (len >= max) throw 0; mem[len++] = e;
	return *this;
	}
	T pop() { if (len == 0) throw 1; return mem[--len]; }
	void print() const { for (uint i = 0; i < len; i++) cout << mem[i]; cout << endl; }
	~Stack() { delete[] mem; }
	Stack& operator=(const Stack& rh) {
		if (this == &rh) return *this; //考虑自己给自己赋值的情况
		delete[] mem;
		mem = new T[rh.max];
		len = rh.len;
		max = rh.max;
		for (uint i = 0; i < len; i++) {
			mem[i] = rh.mem[i];
		}
		return *this;
	}

};

int main() {
	Stack s1(5);
	Stack s2(8);
	Stack s3(s1);
	s3 = s2;				//赋值的时候，还是会重复释放，所以要重写
	/*如果 s3 = s3?，又会出现问题，*/
	s2 = s2;
	s1.push("1"); s1.push("2").push("3").push("4");
	s2.push("张飞").push("关于");
	s1.print();
	s2.print();
}