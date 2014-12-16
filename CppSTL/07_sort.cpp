#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
//每次找到最小的元素，然后和a[i]交换位置
template <typename T>       //这个时候，就不用管a是什么类型的了
void sort(T* a, int n) {        //调用的时候，编译器可以推测
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min])
                min = j;
        }
        swap(a[min], a[i]);
    }
}

template <typename T>       //偏特化
void sort(T* a[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(*a[j] < *a[min])
                min = j;
            }
            swap(a[min], a[i]);
        }
    }

template <>       //为const char* 特化
void sort(const char* a[], int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(strcmp(a[j],a[min]) < 0)
                min = j;
            }
            swap(a[min], a[i]);
        }
    }

struct Date{
    int y, m, d;
    // Date(int y, int m, int d):y(y), m(m), d(d) {}
};

bool operator<(const Date& a, const Date& b) {
    if(a.y < b.y || a.y == b.y && (a.m < b.m || a.m == b.m && a.d < b.d))
        return true;
    else
        return false;
}

ostream& operator<<(ostream& o, const Date&d) {
    return o << d.y << '-' << d.m << '-' << d.d;
}

template <class T>
void show(T a[], int n){
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

/*下面的那个的原始写法
template <typename T, int N>
void show(T& t]) {       //这里定义了一个数组的引用，这引用是一个数组的引用
    int n = sizeof(t)/ sizeof(t[0]);
    for(int i = 0; i < n; i++)
    cout << t[i] << ' ';
    cout << endl;
}
*/

template <typename T, int N>
void show(T(&t)[N]) {       //这里定义了一个数组的引用，这引用是一个数组的引用
    // int n = sizeof(t)/ sizeof(t[0]);
    for(int i = 0; i < N; i++)
        cout << t[i] << ' ';
    cout << endl;
}

template <typename T, int N>
void show(T*(&t)[N]) {
    // int n = sizeof(t)/ sizeof(t[0]);
    for(int i = 0; i < N; i++)
        cout << *t[i] << ' ';
        cout << endl;
    }

template<typename T>
void show(T data){
    cout << data << endl;
}

int main() {
    double m = 123.4;
    show(m);            //如何处理了，这是一个double型，无法直接带入到show()函数模板里面
    int a[5] = {6, 1, 9, 2, 8};
    sort(a, 5);
    double d[4] = {1.2, 3.4, 8.9, 2.1};
    // sort(reinterpret_cast<int*>(d), 4);  强转。。不行哦！
    sort(d, 4);

    Date x[3] = {{2010, 8, 30},{2014, 10, 21},{2014, 7, 23}};
    sort(x, 3);

    // show(x, 3);
    // show(a, 5);
    // show(d, 4);
    //如何做到show(a);show(b)...
    show(x);
    show(a);
    show(d);
    const char* s[3] = {"zhangfei", "quange", "chuangge"};
    sort(s, 3); //这里是地址，如果是地址来比较大小。。这个时候需要特化
    show(s);
    int *ap[4] = {new int(5), new int(2), new int(9), new int(8)};
    double* bp[3] = {new double(1.2), new double(5.6), new double(3.2)};
    sort(ap, 4);
    sort(bp, 3);
    show(ap);
    show(bp);
    return 0;
}
