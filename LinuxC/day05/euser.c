#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int fd;
    int r;
    char buf[1024];
    fd = open("test.txt", O_RDONLY);
    bzero(buf, 1024);
    printf("real user:%d\n", getuid());
    printf("effective user:%d\n", geteuid());
    while((r = read(fd, buf, 1024)) > 0) {
        printf("%s", buf);
    }
    close(fd);
}
