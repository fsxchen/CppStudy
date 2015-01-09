#include <stdio.h>
#include <stdlib.h>
void fun() {
    printf("over\n");
}

main() {
    atexit(fun);
    printf("Process\n");
}
