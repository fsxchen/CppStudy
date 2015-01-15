#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle(int s) {
    printf("OK!\n");
    sleep(5);
    printf("End!\n");
}

void handleinfo(int s, siginfo_t *info, void *d) {
    printf("OK:%d\n", info->si_int);
    sleep(5);
    printf("End\n");
}

main() {
    struct sigaction act = {0};

    // act.sa_handler = handle;
    act.sa_sigaction = handleinfo;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGINT);
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, 0);
    while(1);
}
