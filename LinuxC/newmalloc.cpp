#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int *p1=(int*)malloc(4);
    int *p2=new int;
    int *p3=(int *)malloc(4);
    int *p4=new int;
    int *p5=new int;
    int *p6=new int;

    printf("%p\n", p1);
    printf("%p\n", p2);
    printf("%p\n", p3);
    printf("%p\n", p4);
    printf("%p\n", p5);
    printf("%p\n", p6);
    return 0;
}
