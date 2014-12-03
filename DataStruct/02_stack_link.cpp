#include <iostream>
#include <string>
typedef int T;
#include "02_list.h"
/*使用链表来实现堆*/
using namespace std;


class Stack{
    List l;
public:
    // Stack():cur(0){}
    void push(const T& d);    //数据入栈
    T pop();      //栈顶数据出栈
    const T& top() const;      //取得栈顶的数据
    bool empty() const {return l.empty();}    //是否空栈
    bool full() const {return false;}
    void clear() {l.clear();}   //栈清空（复位）
    int size() const {return l.size();}     //栈中的数据个数
};

void Stack::push(const T& d)  {
    l.push_front(d);
}
T Stack::pop() {
    T t = l.front();
    l.erase(0);
    return t;
}

const T& Stack::top() const {
    return l.front();
}

int main() {
    Stack s;
    try{
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        s.push(6);
    }
    catch(const char* e) {
        cout << "异常：" << e << endl;
    }
    while(!s.empty()) {
        cout << s.pop() << endl;
    }
}
