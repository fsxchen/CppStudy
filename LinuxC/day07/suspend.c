#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle(int s) {
    printf("信号干扰!\n");
}

main() {

    sigset_t sigs;
    sigemptyset(&sigs);
    sigaddset(&sigs, 2);
    sigaddset(&sigs, SIGUSR1);
    signal(SIGUSR2, handle);    //先处理，然后返回

    sigsuspend(&sigs);
    printf("over!\n");
}
