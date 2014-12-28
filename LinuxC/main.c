#include <unistd.h>
//windows.h
#include <stdio.h>
int main() {
    printf("xx%d\n", getpid());
    while(1);
}
