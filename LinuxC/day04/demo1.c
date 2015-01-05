#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int a=9999;
main() {
    int t=888;
    //得到文件名
    //打开文件
    //读取a地址这个位置的数据
    char filename[100];
    int fd;
    long int data=8888;
    sprintf(filename, "/proc/%d/mem", getpid());
    fd=open(filename, O_RDWR);
    if(fd == -1) printf("open error:%m\n"), exit(-1);
    // pread(fd, &data, 4, (long int)&a);
    // lseek(fd, (long int)&a, SEEK_CUR);
    // write(fd, &t, 4);
    // read(fd, &data, 4);
    printf("%d\n", a);
    pwrite(fd, &data, 4, (long int)&a);
    printf("%d\n", a);
    close(fd);
}
