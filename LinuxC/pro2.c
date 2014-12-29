#include <stdio.h>
#include <stdlib.h>

main() {
    // int *a = (int*)0x958010;     //段错误
    // // *a = 9999;
    // printf("%d\n", *a);
    // while(1);
    int *p=malloc(0);
    *p=9999;
    printf("%d\n", *p);
    }
