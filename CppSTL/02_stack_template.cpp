#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template <typename T, int len> //size，模板形参变量，一般是整数，字面量（一旦编译就不变的）
class Stack{        //这个时候，Stack不再是一个类名,所以成员函数,都必须使用模板
    T a[len];
    int cur;
public:
    Stack():cur(0){}
    void push(const T& d)throw(const char*){
        if(full()) throw "满了";
        a[cur++] = d;
    }
    T pop()throw(const char*) {
        if(empty()) throw "空的";
        return a[--cur];
    }
    const T& top() const throw(const char*){
        if(empty()) throw "空的";
        return a[cur-1];
    }
    bool empty() const {return cur == 0;}
    bool full() const {return cur == 5;}
    void clear() {cur = 0;}
    int size() const {return cur;}
};

int main() {
    Stack<char, 20> s;      //模板的实例化：把模板的类型确定下来
    Stack<double, 30> d;    //这个必须在编译的时候就确定了
    // s = d;   错误的
    try{
        ;
        s.push('+');
        s.push('-');
        s.push('*');
        s.push('/');

        d.push(123);
        d.push(456);
    }
    catch(const char *e) {
        cout << "异常:" << e << endl;
    }
    cout << typeid(s).name() << endl;
    cout << typeid(d).name() << endl;
    while(!s.empty()) {
        cout << s.pop() << endl;
    }
    while(!d.empty()) {
        cout << d.pop() << endl;
    }

}
