#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <new>
int main() {

    char a[20];
    int *p = new(a) int;    //定位分配,
    return 0;
}
