//插入法排序，类似与扑克牌整理手牌的方法
void sort(int* a, int n) {
    int j;
    for (int i = 1; i < n; i++) {
        int t = a[i];
        for (j = i; j > 0 && t < a[j - 1]; --j){
            a[j] = a[i - 1];
        }
        a[j] = t;
    }
}
