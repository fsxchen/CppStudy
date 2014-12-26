/*
迭代器
####迭代器分类(it):++, *, ->, ==, !=
输入迭代器：*it 可读，不宜定可写（修改）
输出迭代器：可以设置*it 的值，但不一定能读取*it的值
前向迭代器：可以读取也可设置*it的值
双向迭代器：支持--
随机迭代器：支持+n, -n,比较大小，[下标]，几乎和指针一样
*/
#include <iterator>
#include <iostream>
using namespace std;
#include <vector>
#include "print.h"
#include <fstream>

int main() {
    istream_iterator<int> in(cin);
    istream_iterator<int> end;
    vector<int> vi;
    copy(in, end, back_inserter(vi));
    print(vi.begin(), vi.end());
    ostream_iterator<int> o(cout, "*");
    copy(vi.begin(), vi.end(), o); cout << endl;
    ofstream fo("datafile");
    ostream_iterator<int> fiter(fo, " ");
    copy(vi.begin(), vi.end(), fiter); fo << endl;
    fo.close();
    ifstream fin("datafile");
    istream_iterator<int> fit(fin);
    vector<int> v;
    copy(fit, end, back_inserter(v));
    print(v.begin(), v.end(), ',');
    fin.close();
}
