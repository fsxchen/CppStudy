#include <stdio.h>
#include <signal.h>

void h(int s) {
    printf("非屏蔽信号发生\n");
}

main() {
    sigset_t sigs;
    signal(10, h);
    sigemptyset(&sigs);
    sigaddset(&sigs, 2);
    printf("屏蔽开始\n");
    sigsuspend(&sigs);
    printf("屏蔽结束\n");
}
