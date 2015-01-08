#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>


main() {
    int a = 20;
    int *b = malloc(4);
    *b = 40;
    int *c = mmap(0, 4, PROT_READ| PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, 0, 0);
    *c = 40;

    int *d = sbrk(4);   //也是私有的
    *d = 50;

    if(fork()) {
        printf("%d\n", *b);
        *b=90;
        printf("F C is %d\n", *c);
        *c=90;
        printf("F D is %d\n", *d);
        *d=90;
    } else {
        printf("%d\n", *b);
        sleep(3);
        printf("%d\n", *b);
        printf("C is %d\n", *c);
        printf("D is %d\n", *d);
    }
}
