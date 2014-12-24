#include <iostream>
#include <algorithm>
using namespace std;

void add10(int& element) {
    element += 10;
}

void print(int& element) {
    cout << element << endl;;
}

int main() {
    int a[5] = {11, 22, 33, 44, 55};
    for_each(a, a+5, add10);
    for_each(a, a+5, print);
}
