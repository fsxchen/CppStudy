#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdlib.h>

int fd;
int i = 0;

void end(int s) {
    //关闭管道
    close(fd);
    //删除管道
    unlink("my.pipe");
    exit(-1);
}

main() {
    signal(2, end);
    //建立管道
    mkfifo("my.pipe", 0666);
    //打开管道
    fd = open("my.pipe", O_RDWR);
    //每隔1秒写数据
    while(1) {
        sleep(1);
        write(fd, &i, 4);
        i++;
    }

}
