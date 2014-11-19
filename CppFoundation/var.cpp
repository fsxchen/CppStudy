#include <iostream>
#include <string>

using namespace std;

class F {
	int n;
	int d;
public:
	F(int n = 0, int d = 1);
	void print(bool newline = true);
	void print(bool newline = true) const;
	void input();
	~F();
};

F::~F(){
	cout << "~F()" << n << '/' << d << endl;
}

F::F(int n, int d) : n(n), d(d) {
	cout << "F(" << n << ',' << d << ")\n";
}

void F::print(bool newline) {
	cout << n << '/' << d;
	if (newline) cout << "���ɵ�" << endl;
}

void F::print(bool newline) const {
	cout << n << '/' << d;
	if (newline) cout <<"�����ɵ�"<< endl;
}
int main() {
	F* p = new F;  //��̬�����ڴ�
	F* q = static_cast<F*>(malloc(sizeof(F)));
	F a(1, 2), b(3, 4);
	a.print();

	delete p; p = NULL;
	b.print();

	free(q);

	const F c(5, 6);
	c.print();

	int ab;
	cin >> ab;
	return 0;
}