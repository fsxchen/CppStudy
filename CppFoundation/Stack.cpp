#include <iostream>
#include <string>
using namespace std;
typedef string T;

/*�������캯��������ָ���Աָ���˶�̬��Ԫ�أ�Ĭ�ϵĿ������캯�����Ḵ��ԭ���ĵ�ַso��
1����д�������캯��
2�������Լ�Ҫ��д��ֵ��=��������
3����Ҫд��������
*/
class Stack {
	typedef unsigned int uint;
	T* mem;
	uint max;
	uint len;
public:
	Stack(const Stack& s) :mem(new T[s.max]), max(s.max), len(s.len) {}			//�������캯��
																				//+��������������ʱ����ͷ��ڴ������
															//+������ʹ�����ü���������Ϊÿһ������������һ���µĿռ�
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
		if (this == &rh) return *this; //�����Լ����Լ���ֵ�����
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
	s3 = s2;				//��ֵ��ʱ�򣬻��ǻ��ظ��ͷţ�����Ҫ��д
	/*��� s3 = s3?���ֻ�������⣬*/
	s2 = s2;
	s1.push("1"); s1.push("2").push("3").push("4");
	s2.push("�ŷ�").push("����");
	s1.print();
	s2.print();
}