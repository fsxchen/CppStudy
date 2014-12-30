#include <stdio.h>
#include <stdlib.h>

main() {
    int *a = malloc(4);
    *a = 9999;
    printf("%p\n", a);
    while(1);
}
