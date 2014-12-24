/*
####map的个性
不允许有重复的key
元素是key/value对
支持以key为下标，访问对应的value的引用，如果key不存在，就插入一个新的key/value对
*/
#include <iostream>
using namespace std;
#include "print.h"
#include <map>

struct P{
    string name;
    int age;
public:
    P(){}   //因为map中如果没有key，会创建一个key，所以需要一个无参构造
    P(const char* n, int a):name(n), age(a) {}
};

ostream& operator<<(ostream& o, const P& x) {
    return o<<x.name <<':' << x.age;
}

int main() {
    map<int, P> mis;
    mis.insert(map<int, P>::value_type(5, P("马超", 21)));  //value_type,内部类型
    mis.insert(pair<int, P>(8, P("黄忠", 23)));
    mis.insert(make_pair(4, P("马超", 22)));
    mis[3] = P("孙权", 19);
    mis[6] = P("吕蒙", 21);
    mis.insert(make_pair(5, P("张辽", 22)));
    mis.insert(make_pair(5, P("张辽", 22)));
    print(mis.begin(), mis.end());
    mis[6] = P("张角", 21);
    print(mis.begin(), mis.end());
}
