#include <algorithm>
using std::swap;
//每次找到最小的元素，然后和a[i]交换位置
void sort(int* a, int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min])
                min = j;
        }
        swap(a[min], a[i]);
    }
}
