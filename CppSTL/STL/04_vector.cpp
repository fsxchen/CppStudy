/*
.capacity():当前的容量，如果超过了这个，就需要重新分配
.reserver(n)，约定一个容量n，事先分配一个空间 >= n
下标[]: .operator[](i), 这个不会越界检查， .at(i)，越界的时候会抛出异常
*/

#include <iostream>
using namespace std;
#include <vector>
#include "print.h"
#include <exception>
#include <typeinfo>

int main() {
    vector<double> vd, vv;
    for(int i = 0; i < 9; i++) {
        vd.push_back(i + 0.1);
        cout << &*vd.begin() << ':';        //插入和删除的时候，迭代器的地址可能会失效，所以需要重新取得
        cout << vd.size() << '/' << vd.capacity() << endl;
    }
    cout << "=========================" << endl;
    vv.reserve(9);
    for(int i = 0; i < 9; i++) {
        vv.push_back(i + 0.1);
        cout << vv.size() << '/' << vv.capacity() << endl;
    }
    vd[3] = 123.45;
    vv.at(5) = 67.8;
    for(int i = 0; i <= vd.size(); i++) {       //这个越界，但是不会抛出异常
        cout << vd[i] << ' ';
    }
    cout << endl;
    try{
        for(int i = 0; i <= vd.size(); i++) {
            cout << vd.at(i) << ' ';   //这个越界，会抛出异常
        }
        cout << endl;
    }catch(exception& e) {
        cout << "异常：" << e.what() << endl;
        cout << "类型：" << typeid(e).name() << endl;
    }
}

template <typename T>
void show(T a[], int n);
