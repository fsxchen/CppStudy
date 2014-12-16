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

template <typename T>       //偏特化
T Min(const T& a, char b) {
    cout << 'E'; return a < b ?a:T(b);
}

template <>       //全特化,针对已经有的模板做的特化
double& Min(double& a, double& b) {
    cout << 'F'; return a < b ?a:b;
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
    cout << Min(123, 'x') << endl;
}
