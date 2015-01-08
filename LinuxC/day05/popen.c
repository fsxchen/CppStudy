#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
main() {
    char buf[1024];
    FILE * fp =popen("ls -l", "r");
    int fd = fileno(fp);
    int r;
    printf("==========================\n");
    while((r = read(fd, buf, 1024)) > 0) {
        buf[r] = 0;
        printf(":::%s", buf);
    }
    printf("==========================\n");
    close(fd);
    pclose(fp);

}
