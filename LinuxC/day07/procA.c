#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

main() {
    int *p;
    int fd;
    int i = 0;
    fd = open("tmp", O_RDWR | O_CREAT);
    ftruncate(fd, 4);

    p = mmap(0, 4, PROT_READ| PROT_WRITE, MAP_SHARED, fd, 0);
    while(1) {
        sleep(1);
        *p = i;
        i++;
    }
    close(fd);
}
