#include <iostream>
using namespace std;

typedef int T;
#include "02_list.h"

class Queue{
    List l;
public:
    Queue& push(const T& d) {
        l.push_back(d);
        return *this;
    }
    T pop(){
        T t = l.front();
        l.erase(0);
        return t;
    }
    const T& front() const {return l.front();}
    const T& end() const {return l.end();}
    int size() const{return l.size();}
    void clear() {l.clear();}
    bool empty() {return l.empty();}
    bool full() {return false;}
};

int main() {
    Queue q;
    q.push(1).push(2).push(3);
    q.push(4);
    // cout << q.pop() << ',' << q.pop() << endl;  注意：无法保证数据
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    q.push(10).push(11).push(19);
    while(!q.empty())
        cout<<q.pop() << endl;
}
