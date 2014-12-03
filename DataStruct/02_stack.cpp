#include <iostream>
#include <string>
using namespace std;

typedef string T;
class Stack{
    T a[8];
    int cur;
public:
    Stack():cur(0){}
    void push(const T& d)throw(const char*);    //数据入栈
    T pop()throw(const char*);      //栈顶数据出栈
    const T& top() const throw(const char*);      //取得栈顶的数据
    bool empty() const {return cur == 0;}    //是否空栈
    bool full() const {return cur == 5;}     //是否已满
    void clear() {cur = 0;}   //栈清空（复位）
    int size() const {return cur;}     //栈中的数据个数
};

void Stack::push(const T& d) throw(const char*) {
    if(full()) throw "满了";
    // a[cur] = d;
    // cur++;
    a[cur++] = d;
}
T Stack::pop() throw(const char*){
    if(empty()) throw "空的";
    return a[--cur];
}

const T& Stack::top() const throw(const char*){
    if(empty()) throw "空的";
    return a[cur-1];
}
int main() {
    Stack s;
    try{
        s.push("你好");
        s.push("世界");
        s.push("张飞");
        s.push("赵云");
        s.push("关羽");
        s.push("刘备");
    }
    catch(const char *e) {
        cout << "异常:" << e << endl;
    }
    while(!s.empty()) {
        cout << s.pop() << endl;
    }
}
