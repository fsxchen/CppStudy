#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main() {
    int fd[2];
    pipe(fd);
    if(fork()) {
        //父进程
        close(fd[0]);       //只负责写数据
        while(1) {
            write(fd[1], "Hello", 5);
            sleep(1);
        }
    } else {
        //子进程
        int r;
        char buf[20];
        close(fd[1]);       //只负责读数据

        while(1) {
            r = read(fd[0], buf, 20);
            buf[r] = 0;
            printf("::%s\n", buf);
        }
    }
}
