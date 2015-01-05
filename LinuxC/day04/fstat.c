#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
main() {
    int fd;
    struct stat st;
    fd = open("stu.dat", O_RDONLY);
    if(fd == -1) printf("open error:%m\n"), exit(-1);
    fstat(fd, &st);
    printf("%d, %o\n", (int)st.st_size, st.st_mode);
    close(fd);
}
