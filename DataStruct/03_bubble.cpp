#include <algorithm>
//冒泡排序，总是比较相邻的两个数，直到没有可以交换的为止
using std::swap;
void sort(int* a, int n) {
    bool changed;
    do{
        changed = false;
        for (int i = 0; i < n; i ++) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i-1]);
                changed = true;
            }
        }
        --n;
    }while(changed);
}
