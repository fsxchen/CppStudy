#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle(int s) {
    printf("信号干扰!\n");
}

main() {
    int sum = 0;
    int i;
    sigset_t sigs;
    sigemptyset(&sigs);
    sigaddset(&sigs, SIGINT);

    signal(SIGINT, handle);
    sigprocmask(SIG_BLOCK, &sigs, 0);
    for(i = 0; i < 10; i++) {
        sum += i;
        sleep(1);       //模拟业务时间比较长
    }
    printf("%d\n", sum);
    sigprocmask(SIG_UNBLOCK, &sigs, 0);
    printf("over!\n");
}
