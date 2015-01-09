#include <unistd.h>
#include <stdio.h>
#include <signal.h>

main() {
    while(1) {
        printf("进程在执行\n");
        sleep(1);
    }
}
