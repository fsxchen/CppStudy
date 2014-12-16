#include <iostream>
#include <cstring>
using namespace std;
template <typename T>
const T& Min(const T& a, const T& b){
    cout << 'A';return a < b ? a: b;
}

template <typename T>
T& Min(T& a, T& b){         //这个和上面来比，编译器会选择相对比较自由的那个，
    cout << 'A';return a < b ? a: b;
}

template <typename T, typename U>
T Min(const T& a, const U& b) {
    cout << 'C'; return a < b ?a:T(b);
}

const char* Min(const char* a, const char* b) {     //如果普通函数和模板都可用的时候，编译器优先考虑普通函数
    cout << 'D'; return strcmp(a, b) < 0?a:b;
}


int main() {
    int m = 20, n = 10;
    cout << Min(m, n) << endl;
    double x = 1.1, y = 2.2;
    cout << Min(x, y) << endl;
    cout << Min(5.9, 6) << endl;
    cout << Min("hello", "world") << endl;
    cout << Min<>("hello", "world") << endl;    //调用模板函数
}
