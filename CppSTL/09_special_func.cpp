#include <iostream>
using namespace std;

template <typename T, typename U>
struct Pair{
    T first;
    U second;
    Pair():first(), second() {}
    Pair(const T& a, const U&b):first(a), second(b){}
};

template <typename T, typename U>
ostream& operator<<(ostream& o, const Pair<T, U>& p) {
    return o << p.first << ':' << p.second;
}

template <typename T, typename U>
Pair<T, U> mp(T f,U s) {        //函数的自动类型推测
    return Pair<T, U>(f, s);
}

int main() {
    cout << Pair<const char *, int>("芙蓉", 18) << endl;
    cout << Pair<int, double>(20, 6789.5) << endl;  //类里面，需要这么加
    cout << mp("芙蓉", 18) << endl;   //利用函数模板的自动类型推断
    cout << mp(20, 6789.5) << endl;
}
