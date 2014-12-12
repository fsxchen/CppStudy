#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T>
class Fact<T> {
public:
    enum {val=Fact<n-1>::val* n};
};

template <int n>
class Fact<0> {
public:
    enum {val=1};
};

template <typename T>
class Type{
public:
    static string name() {return typeid(T).name();}
};
template<>
class Type<char> {
public:
    static string name() {return "char";}
};

template<>
class Type<double> {
public:
    static string name() {return "double";}
};

template<>
class Type<int> {
public:
    static string name() {return "int";}
};

template<>
class Type<bool> {
public:
    static string name() {return "bool";}
};

template<typename T>        //偏特化
class Type<T*> {
public:
    static string name() {return Type<T>::name()+ " pointer";}
};
int main() {
    return 0;
}
