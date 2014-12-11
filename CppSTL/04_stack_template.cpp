#include <iostream>
#include <cstring>
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

template <int len> //模板特例化，不许要指定len
class Stack<const char*, len>{ //const char* 特化
    string a[len];
    int cur;
public:
    const char* element() const{return "const char*";}
    int max_size() const {return len;}
    Stack():cur(0){}
    void push(const char*& d)throw(const char*){
        if(full()) throw "满了";
        a[cur++] = d;
    }
    const char* pop()throw(const char*) {
        if(empty()) throw "空的";
        return a[--cur].c_str();
    }
    const char*& top() const throw(const char*){
        if(empty()) throw "空的";
        return a[cur-1].c_str();
    }
    bool empty() const {return cur == 0;}
    bool full() const {return cur == len;}
    void clear() {cur = 0;}
    int size() const {return cur;}
};

int main() {
    char buf[100];
    Stack<const char*, 10> s; //如何将const * 这种类型，里面存放字符串呢？
    /*
    aaa
    bbb
    ccc
    ddd
    end
    end
    end
    end
    end
    这个时候，我们需要一个专门针对与const char* 专门处理的
    */
    for (;;) {
        cin >> buf;
        if(strcmp(buf, "end")== 0) break;
        s.push(buf);
    }

    while(!s.empty()) cout << s.pop() << endl;
}
