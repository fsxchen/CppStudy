#include <iostream>
#include <typeinfo>

using namespace std;
template <int n>
class Fact {
public:
    enum {val=Fact<n-1>::val*n};
};

template <>
class Fact<0> {
public:
    enum {val=1};
};

template<typename T>
class Type {
public:
    static string getname() {return typeid(T).name();}
};

template<>          //类模板特话
class Type<char> {
public:
    static const char* const getname() {return "char";}
};

template<>          //类模板特话
class Type<bool> {
public:
    static const char* const getname() {return "bool";}
};

template <typename T>
class Type<T*> {        //这个是偏特化
public:
    static string getname() {return Type<T>::getname() + " pointer";}
};

int main() {
    cout << Fact<5>::val << endl;
    cout << Type<double>::getname() << endl;
    cout << Type<char>::getname() << endl;
    cout << Type<bool>::getname() << endl;
    cout << Type<int *>::getname() << endl;
}
