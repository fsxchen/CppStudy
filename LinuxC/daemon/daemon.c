#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int daemon_init() {
    pid_t pid;
    if((pid = fork()) < 0) return -1;
    else if(pid != 0)
        exit(0);
    setsid();
    printf("hello\n");
    sleep(10);
    printf("ls\n");

    return 0;
}

int main() {
    daemon_init();
}