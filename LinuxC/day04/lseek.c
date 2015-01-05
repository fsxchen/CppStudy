#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
main() {
    int fd ;
    float score;
    int r;
    int i = 0;
    fd = open("stu.dat", O_RDONLY);
    if(fd == -1) printf("open error:%m\n"), exit(-1);


    //定位
    // for(i = 0; i < 2; i++){
    //     r = lseek(fd, i*28, SEEK_SET);    //刚打开，可以使用相对位置
    //     //读取
    //     //打印 输出
    //     r= lseek(fd, 24, SEEK_CUR);
    //     r= read(fd, &score, sizeof(float));
    //     printf("%.2f\n", score);
    //
    //
    // }
    // r = lseek(fd, -100, SEEK_SET);
    // write(fd, "hello", 6);
    // printf("%d\n", r);
    for(i = 0; i < 2; i++) {
        pread(fd, &score, sizeof(float),i*28+24);
        printf("%.2f\n", score);
    }
    close(fd);
}
