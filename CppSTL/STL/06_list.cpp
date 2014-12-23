/*
####list的特性，一个双向链表
增删.push_front(element), .pop_front()  .remove(element)//删除所有和element相等的元素,可以重写==来改变，所以需要支持等号运算符
不支持下标[]
除重：.unique() 去除相邻的重复元素，相邻的无论多少个，只保留一个
排序：.sort(compare_func=less) ，默认是小于符号，从小到大，要支持<,可以传递一个比较函数，使用指定的函数比较
倒置:.reverse()颠倒链表中的元素
合并：转移 .splice(pos, list2)      //把list2转移过来, list2空了
.splice(pos, list2, pos2)   //转移指定位置
.splice(pos, list2, pos_beg, pos_end) 转移一个区间
归并：两个有序的合并后仍然有序 .merge(list2)

*/
#include <iostream>
using namespace std;
#include <list>
#include "print.h"
#include <cassert>

bool compare(int x, int y) {
    x%=3, y %=3;
    return x < y;
}

int main() {
    int a[10] = {3, 8, 8, 8, 5, 5, 1, 8, 8, 7}, b[6] = {9, 3, 5, 2, 7, 6};
    list<int> li(a, a+10), lili(b, b+6);
    print(li.begin(), li.end());
    li.unique();
    print(li.begin(), li.end());
    li.sort();
    print(li.begin(), li.end());
    li.unique();
    print(li.begin(), li.end());
    li.reverse();
    print(li.begin(), li.end());
    li.splice(li.begin(), lili);
    print(li.begin(), li.end());
    assert(lili.empty());
    li.remove(5);
    print(li.begin(), li.end());
    li.sort(); li.unique();
    print(li.begin(), li.end());
    lili.push_back(0), lili.push_back(4), lili.push_back(5);
    lili.push_back(7), lili.push_back(10);
    lili.sort();
    print(lili.begin(), lili.end());
    li.merge(lili);
    print(li.begin(), li.end());
    lili.assign(b, b+6);
    print(lili.begin(), lili.end());
    lili.sort(greater<int>());
    print(lili.begin(), lili.end());
    lili.sort(compare);
    print(lili.begin(), lili.end());
}
