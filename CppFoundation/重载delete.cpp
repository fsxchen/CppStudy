#include <iostream>
#include <string>

using namespace std;
char mem[1000];
int pos;

class A {			//�κ�һ���࣬����ռ��һ���ֽ�
public:
	A() { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
	static void* operator new[](size_t bytes){  //new ������,��ʹ��д��Ҳ�Ǵ������static
		cout << "size is" << bytes << endl;   //�������7���� newһ�������ʱ�򣬻����ķ���4���ֽڣ�����������ĳ���
		cout << "new A" << endl;				//+���������������������delete����
		int alloc = pos;
		pos += bytes;
		return mem + alloc;
	
	}   
	void operator delete[](void* p) {				//static
		cout << "delete A" << endl; 
		
	}			

};

int main() {
	A *x = new A;		//1������ռ� 2��ִ�й��캯��
	delete x;			//1��ִ���������� 2���ͷſռ�

	x = new A[3];		//��������飬���һ��[]
	delete[] x;

	int ma;
	cin >> ma;
}

