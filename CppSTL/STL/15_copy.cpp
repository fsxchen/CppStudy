#include <iostream>
using namespace std;
#include <vector>
#include "print.h"
#include <algorithm>
#include <deque>

template <typename Iter, typename Pos>
void co(Iter ib, Iter ie, Pos p) {
    while(ib != ie) *p++ = *ib++;
}

int main() {
    int a[5] = {3, 9, 2, 6, 8};
    int b[8] = {0};
    vector<int> vi(a, a+5);
    sort(vi.begin(), vi.end());
    print(vi.begin(), vi.end());
    print(a, a+5, ',');
    copy(vi.begin(), vi.end(), a);
    print(a, a+5, ',');
    co(vi.begin(), vi.end(), b);
    print(b, b + 8);                //2 3 6 8 9 0 0 0
    //co(b, b+5, b+3);              //+2 3 6 2 3 6 2 3
    copy_backward(b, b+5, b+8);     //倒着复制
    print(b,b+8);
    bool func(int);
    deque<int> v;
    co(a,a+5,back_inserter(v));
    print(v.begin(), v.end());
    co(a,a+5,front_inserter(v));        //插入器
    print(v.begin(), v.end());
    v.clear();
    remove_copy_if(a,a+5,back_inserter(v),func);
    print(v.begin(), v.end());
}
bool func(int n){return n&1;}
