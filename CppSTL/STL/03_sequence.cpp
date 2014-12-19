/**
####序列式容器的工性（vector, deque, list）
指定元素的个数
同时指定元素的个数和初始值，()默认是零初始化)
插入：.insert(pos, n, element),(某个位置赋值n个) insert(pos, pos_beg, pos_end)
赋值：.assign(n, element)， assign(pos_beg, pos_end)
调整：.resize(n, element=零初始化) 重新调整大小
首尾：可以访问首尾.front(), .back()
末尾增删：.push_back(element),    .pop_back() 这个只是负责删除，不会返回数据，返回void
**/

#include <deque>
#include <iostream>
using namespace std;
#include "print.h"
#include <string>

int main() {
    deque<string> ds;
    // deque< vector<int> >  注意这里的操作
    ds.push_back("张飞");
    ds.push_back("关羽");
    ds.push_back("大乔");
    ds.push_back("小乔");
    print(ds.begin(), ds.end(), ',');
    ds.insert(++++ds.begin(), 2, "刘备");
    print(ds.begin(), ds.end(), ',');
    string s[3] = {"曹操", "孙权", "董卓"};
    ds.insert(----ds.end(), s, s+3);    //在指定位置插入一个区间
    print(ds.begin(), ds.end(), ',');
    ds.pop_back(); ds.pop_back();
    print(ds.begin(), ds.end(), ',');
    cout << "front:" << ds.front() << ",back:" << ds.back() << endl;
    // front back 返回的是引用
    ds.resize(12, "张辽");
    print(ds.begin(), ds.end(), ',');
    ds.assign(5, "诸葛亮");
    print(ds.begin(), ds.end(), ',');
    ds.front() = "徐褚"; ds.back() = "吕布";
    print(ds.begin(), ds.end(), ',');
}
