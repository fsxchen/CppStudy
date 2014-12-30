#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
main() {
    int *p=mmap(
        NULL,      //NULL
        getpagesize(),      //得到返回内存分配的基本单位
        PROT_READ|PROT_WRITE,
        MAP_ANONYMOUS|MAP_SHARED,
        0, 0);
    *p = 20;
    *(p+1) = 30;
    *(p+2) = 40;
    printf("%d\n", p[2]);
    munmap(p, 4096);
}
