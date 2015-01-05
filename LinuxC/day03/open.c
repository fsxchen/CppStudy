/*创建文件*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main()
{
    int fd;

    char name[20];
    short age;
    float score;
    char sex;

    fd=open("test.dat",
    O_RDWR|O_CREAT|O_EXCL,
    00666);
    if(fd==-1) printf("open error:%m\n"),exit(-1);


    //写第一条
    memcpy(name,"tom",strlen("tom")+1);
    age=20;
    score=99.99;
    sex='F';

    write(fd,name,sizeof(name));
    write(fd,&age,sizeof age);
    write(fd,&score,sizeof(float));
    write(fd,&sex,sizeof(sex));

    //写第二条
    memcpy(name,"Bush",strlen("Bush")+1);
    age=70;
    score=65.00;
    sex='M';
    write(fd,name,sizeof(name));
    write(fd,&age,sizeof age);
    write(fd,&score,sizeof(float));
    write(fd,&sex,sizeof(sex));

    //写第三条

    memcpy(name,"达内",strlen("达内")+1);
    age=10;
    score=99.00;
    sex='F';
    write(fd,name,sizeof(name));
    write(fd,&age,sizeof age);
    write(fd,&score,sizeof(float));
    write(fd,&sex,sizeof(sex));

    close(fd);
}
