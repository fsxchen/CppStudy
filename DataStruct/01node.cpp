#include <iostream>
using namespace std;

typedef int T;
struct Node {
	T data;
	Node* next;
	Node(const T& d):data(d), next(NULL) {}  //构造函数
	operator T() {return data;}  //java里面，有个toString

};

void showlist(Node* head) {
	Node* p = head;
	while(p) {
		cout << *p << ' ';
		p = (*p).next;	
	}
	cout << endl;
}


int main() {
	Node a(10), b(20), c(30), d(40), e(50), f(60);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	showlist(&a);
	Node* p = &a;

	e.next = b.next;  //&c
	b.next = &e;
	
	showlist(&a);

	Node *k = new Node(70);
	k->next = c.next;
	c.next = k;
	showlist(&a);
	delete k;


	
}

