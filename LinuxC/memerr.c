#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

extern int errno;
int main() {
    void *p=sbrk(10000000000*3);
    if(p ==(void*)-1) {
        // printf("err\n");
        perror("Hello:");
        printf("Memory:%m\n");
        printf("%s\n", strerror(errno));
    }
}
