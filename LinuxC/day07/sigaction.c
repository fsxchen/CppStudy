#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle(int s) {
    printf("OK!\n");
    sleep(5);
    printf("End!\n");
}

main() {
    struct sigaction act = {0};

    act.sa_handler = handle;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGINT);
    act.sa_flags = 0;
    sigaction(SIGUSR1, &act, 0);
    while(1);
}
