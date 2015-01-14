#include <stdio.h>
#include <signal.h>
void handle(int s) {
    printf("Hello! start\n");
    sleep(10);
    printf("Hello!end\n");
}

main() {
    signal(2, handle);
    while(1) {

    }
}
