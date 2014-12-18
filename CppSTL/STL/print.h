#ifndef PRINT_H
#define PRINT_H 1
//输出指定区间的数据，包含头，不包含尾
#include <iostream>
template <typename T>
void print(T b, T e) {
    while(b!= e)
        cout << *b++ << ' ';
    cout << endl;
}
#endif
