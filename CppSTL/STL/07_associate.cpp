/*
####关联式容器共性，都是用二叉查找树来实现的，都会自动根据关键字排序
**关联式容器包括 set<K>, multiset<T>, map<K, V>, multimap<K, V>**
查找：.find(key)  ，返回第一个指向这个元素的迭代器，如果没有找到，返回.end()指向无效位置
统计：.count(key), 统计关键字key的个数
删除：.erase(key),删除关键字key相等的所有元素
区间：.lower_bound(key)取得关键字为key第一个的元素
和.upper_bound(key)取得关键字为key的最后一个元素的位置
.equal_range(key)一次取得关键字为key的元素区间，返回的是一个pair模板
插入：插入元素不用指定位置 .insert(element);//也支持指定位置
构造函数可以用比较函数作为参数bool(*compare)(K a, K b)
*/
#include <set>
#include <iostream>
using namespace std;
#include "print.h"

struct Person {
    string name;
    int age;
public:
    Person(const char* n, int a):name(n), age(a) {}
};
bool operator<(const Person& a, const Person& b) {
    return a.age < b.age || a.age==b.age && a.name < b.name;
}
ostream& operator<<(ostream& o, const Person& x) {
    return o<<x.name <<':' << x.age;
}
int main() {
    multiset<Person> mp;
    mp.insert(Person("赵云", 16));
    mp.insert(Person("张飞", 18));
    mp.insert(Person("刘备", 20));
    mp.insert(Person("诸葛亮", 19));
    mp.insert(Person("孙尚香", 15));
    mp.insert(Person("孙尚香", 15));
    mp.insert(Person("孙尚香", 15));
    mp.insert(Person("赵云", 16));
    mp.insert(Person("张飞", 18));
    mp.insert(Person("刘备", 20));
    mp.insert(Person("赵云", 16));
    mp.insert(Person("张飞", 18));
    mp.insert(Person("刘备", 20));
    print(mp.begin(), mp.end());
    multiset<Person>::iterator it = mp.find(Person("刘备", 20));
    if(it == mp.end()) cout << "没有找到哦！亲" << endl;
    else cout << "发现目标" << *it << endl;
    it = mp.find(Person("曹操", 20));
    if(it == mp.end()) cout << "没有找到哦！亲" << endl;
    else cout << "发现目标" << *it << endl;
    it = mp.find(Person("孙尚香", 15));
    cout << mp.count(*it) << "个" << *it << endl;
    it = mp.find(Person("张飞", 18));
    cout << mp.count(*it) << "个" << *it << endl;
    multiset<Person>::iterator ib, ie;
    ib = mp.lower_bound(Person("赵云", 16));
    ie = mp.upper_bound(Person("赵云", 16));
    cout << "=======================" << endl;
    print(ib, ie);
    cout << "=======================" << endl;
    pair<multiset<Person>::iterator, multiset<Person>::iterator
    >p = mp.equal_range(Person("张飞", 18));
    print(p.first, p.second);
    typedef multiset<Person>::iterator Iter;
    pair<Iter, Iter>q = mp.equal_range(Person("刘备", 20));
    cout << "=======================" << endl;
    mp.erase(Person("孙尚香", 15));
    mp.erase(Person("刘备", 20));
    print(mp.begin(), mp.end());
}
