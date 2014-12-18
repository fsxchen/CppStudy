/*
vector, deque, list, set/map, multi
都是类模板
都有构造函数，一个无参构造函数，一个拷贝构造函数，还有一个区间构造，使用两个迭代器来表示位置
当让都有一个析构
####迭代器相关
迭代器都提供 .begin(), .end() 的方法 返回反向的迭代器 iterator
rbegin()， rend() 反向的迭代器 返回反向的迭代器     reverse_iterator
const_iterator, const_reverse_iterator   只读的
迭代器都支持 *, ->， ==，!=, =, ++, 标准迭代器还支持 --
插入：insert(pos, element)  pos是个迭代器，表示位置
删除：.erase(pos), .erase(pos_beg, pos_end)
清除：.claer()
大小：.size(), .max_size(), .empty()
交换：c1.swap(c2)  swap(c1, c2) 两个容器交换内容
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "print.h"


int main() {
    int a[5] = {33, 11, 55, 22, 44};
    vector<int> vi(a, a+5);
    cout << vi.size() << endl;
    sort(vi.begin(), vi.end());
    vector<int>::iterator b = vi.begin();       //区间初始化
    print(vi.begin(), vi.end());
    print(a, a+5);
    print(vi.rbegin(), vi.rend());          //反向
    vi.insert(++++vi.begin(), 66);
    vi.insert(vi.begin(), 77);
    vi.insert(vi.end(), 88);
    print(vi.begin(), vi.end());
    cout << vi.size() << '/' << vi.max_size() << endl;
    vi.erase(------vi.end());
    print(vi.begin(), vi.end());
    vi.erase(++++vi.begin(),--vi.end());
    print(vi.begin(), vi.end());
    vector<int> v2(a, a + 5);
    print(v2.begin(), v2.end());
    vi.swap(v2);
    cout << "=================" << endl;
    print(vi.begin(), vi.end());
    print(v2.begin(), v2.end());
    cout << "=================" << endl;
    swap(vi, v2);
    print(vi.begin(), vi.end());
    print(v2.begin(), v2.end());
    cout << "=================" << endl;
    vector<int> x;
    cout << "当前容器的容量" << x.capacity() << endl;

    // for(int i = 0; i < 5; i++)
    //     cout << a[i] << ',';
    // cout << endl;
}
