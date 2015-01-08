#include <stdio.h>
#include <unistd.h>

int main() {
    printf("创建进程前!\n");
    int pid=fork();
    if(pid == 0) {
        printf("子进程\n");
        sleep(1);
    }
    else {
        printf("父进程\n");
        sleep(1);
    }
    return 0;
}
