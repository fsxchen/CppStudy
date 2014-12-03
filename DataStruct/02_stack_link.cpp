#include <iostream>
#include <string>
#include "02_list.h"
using namespace std;

typedef string T;
class Stack{

};

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
