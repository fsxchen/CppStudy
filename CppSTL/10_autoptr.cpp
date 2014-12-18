#include <iostream>
using namespace std;

//autoptr 大致的实现
template <typename T>
class autoptr{
    T* p;
public:
    autoptr(T* p):p(p) {}
    ~autoptr() {delete p;}
    autoptr(autoptr& a):p(0) {operator=(a);}     //拷贝构造
    autoptr& operator=(autoptr& a) {        //指针赋值
        if(this == &a) return *this;
        if(p) delete p;
        p = a.p;
        a.p = NULL;
    }

    T& operator*() const {return *p;}
    T* operator->(){return p;}
};

class A{
    int data;
public:
    A(int d):data(d) {cout << this << "A(" << d << ")=" << endl;}
    ~A() {cout << this << "~A()" << data << endl;}
    void show()const{cout << this << ":" << data << endl;}
};
int main() {
    autoptr<A> p(new A(10));
    p->show();
    autoptr<A> q(p);
    //p->show();     出错，这个时候p已经不指向这个对象，而是q指向了
    q->show();
    autoptr<A> r(new A(20));
    (*r).show();
    r = q;
}
