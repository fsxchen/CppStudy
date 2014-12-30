#include <stdio.h>

/*
int add(int a, int b) {
    return a+b;
}
*/

int __attribute__((fastcall)) add(int *a, int *b) {
    return (*a) + (*b);
}

main() {
    /*
    // int (*func)(int) = (int(*)(int))add;
    typedef int(*fun)(int, int, int);
    fun f = (fun)add;
    // int r=f(20);
    int r = f(20, 30, 40);
    printf("%d\n", r);
    */
    int a=20;
    int b=30;
    int r=add(&a, &b);
    printf("%d\n", r);
}
/*
output:
257795404
output:
50
明明只有一个参数？
函数其实也是一个指针，
*/
