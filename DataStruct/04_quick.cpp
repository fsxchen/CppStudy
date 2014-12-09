#include <algorithm>
using std::swap;

//快速排序算法
void sort(int *a, int n) {
    if(n <= 1) return;
    if(n == 2) {
        if(a[1] < a[0]) swap(a[1], a[0]);
        return;
    }
    swap(a[n/2], a[0]); //这里是想找一个主元，这里找了一个中间的当作主元
    int jie= a[0];  //
    int *L = a+1;
    int* R = a + n -1;
    while(L < R) {
        while(L < R &&*L < jie) ++L;        //左边的都比主元小
        while(!(*R < jie) && a < R) --R;    //右边的都不小于主元
        if(L < R) swap(*L, *R);
    }
    if(*R < jie) swap(*R, a[0]);
    sort(a, R - a);
    sort(R+1, n - 1 - (R - a));
}
