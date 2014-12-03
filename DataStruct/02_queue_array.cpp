#include <iostream>
using namespace std;

typedef int T;

class Queue{
    T a[5];
    int b, n;   //队首、和有效元素个数
public:
    Queue():b(0), n(0) {}
    Queue& push(const T& d) {
        if(full()) throw "满了";
        a[(b+n++)%5] = d;
        return *this;
    }
    T pop() {
        if(empty()) throw "空了";
        --n;
        return a[b++%5];
    }
    const T& front() {return a[b%5];}
    const T& end() {return a[(b+n-1)%5];}
    int size() {return n;}
    void clear() {b = 0, n = 0;}
    bool empty() {return n == 0;}
    bool full() {return n == 5;}
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
