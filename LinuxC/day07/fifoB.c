#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdlib.h>

int fd;
int i;

void end(int s) {
    //关闭管道
    close(fd);
    exit(-1);
}

main() {
    signal(2, end);

    //打开管道
    fd = open("my.pipe", O_RDWR);
    shutdown(fd, SHUT_WR);  //关掉写的权限
    //每隔1秒写数据
    while(1) {
        read(fd, &i, 4);
        printf("%d\n", i);
    }
}
