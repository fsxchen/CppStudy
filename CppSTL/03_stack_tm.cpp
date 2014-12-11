#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template <typename T=int, int len=10> //编译的时候就要定下来。模板形参，也可以有默认值
class Stack{        //这个时候，Stack不再是一个类名,所以成员函数,都必须使用模板
    T a[len];
    int cur;
public:
    const char* element() const{return typeid(T).name();}
    int max_size() const {return len;}
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
    Stack<float> f;
    Stack<> a;
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
    cout << s.size() << '/' << s.max_size() << ':' << s.element() << endl;
    cout << d.size() << '/' << d.max_size() << ':' << d.element() << endl;
    cout << f.size() << '/' << f.max_size() << ':' << f.element() << endl;
    cout << a.size() << '/' << a.max_size() << ':' << a.element() << endl;

}
