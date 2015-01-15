#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd[2];
    int r;
    r = pipe(fd);
    char buf[20];
    write(fd[1], "hello", 5);
    write(fd[1], "world", 5);

    r = read(fd[0], buf, 20);
    buf[r] = 0;
    printf("%s\n", buf);
    write(fd[1], "louis", 5);
    r = read(fd[0], buf, 20);
    buf[r] = 0;
    printf("%s\n", buf);

    printf("%d\n", getpid());
    while(1);
}
