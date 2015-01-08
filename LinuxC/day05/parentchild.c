#include <stdio.h>
#include <unistd.h>

main() {
    if(fork()) {
        while(1) {
            printf("parent\n");
        }

    } else {
        while(1) {
            printf("child\n");
        }
    }
}
