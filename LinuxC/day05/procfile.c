#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>


main() {
    // int fd=open("test.txt", O_RDWR);
    // if(fork()) {
    //     // char buf[1024] = {0};
    //     // read(fd, buf, 1024);
    //     // printf("parent:%s\n", buf);
    //     write(fd, "Hello", 5);
    //     close(fd);
    // } else {
    //     // lseek(fd, 0, SEEK_SET);
    //     // char buf[1024] = {0};
    //     // read(fd, buf, 1024);
    //     // printf("child:%s\n", buf);
    //     write(fd, "World", 5);
    //     close(fd);
    // }

    if(fork()) {
        int fd=open("test.txt", O_RDWR);     //在里面的话，会覆盖
        sleep(5);
        printf("%d\n", fd);
        write(fd, "Hello", 5);
        close(fd);
    } else {
        int fd=open("test.txt", O_RDWR);
        printf("%d\n", fd);
        write(fd, "World", 5);
        sleep(8);
        close(fd);
    }
}
