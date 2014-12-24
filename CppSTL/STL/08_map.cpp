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

int main() {
    map<int, string> mis;
    mis.insert(map<int, string>::value_type(5, "马超"));  //value_type,内部类型
    mis.insert(pair<int, string>(8, "黄忠"));
    mis.insert(make_pair(4, "马超"));
    mis[3] = "孙权";
    mis[6] = "吕蒙";
    mis.insert(make_pair(5, "张辽"));
    mis.insert(make_pair(5, "张辽"));
    print(mis.begin(), mis.end());
    mis[6] = "张角";
    print(mis.begin(), mis.end());
}
