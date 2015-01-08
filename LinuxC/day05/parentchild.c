#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
void deal(int s) {
    int status;
    printf("parent!\n");
    wait(&status);
    printf("回收中...\n");
    sleep(5);
    printf("回收完毕！%d\n", WEXITSTATUS(status));
}

main() {
    if(fork() == 0) {
        printf("child推出!\n");
        sleep(2);
        exit(99);
    } else {
        signal(17, deal);
        while(1)
        {
            printf("XXXXXXXX\n");
            sleep(200);
        }
    }
}
