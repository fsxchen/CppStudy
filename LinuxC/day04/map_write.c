#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/mman.h>

struct stu {
    char name[20];
    int age;
    float score;
};
main() {
    int fd;
    int i;
    struct stu* s;  //返回文件在虚拟内存中映射的首地址
    int size;   //文件大小
    int count;  //记录条数
    struct stat st;
    struct stu record;
    memset(&record, 0, sizeof(struct stu));
    //打开一个文件

    fd = open("newstu.dat", O_RDWR|O_CREAT|O_EXCL, 06666);    //创建文件
    if(fd == -1) {
        fd=open("newstu.dat", O_RDWR);
        if(fd == -1) printf("open error:%m\n"), exit(-1);
    }
    //得到文件大小，文件记录条数
    fstat(fd, &st);
    size=st.st_size;
    count=size/sizeof(struct stu);  //记录条数
    //文件大小只要在munmap之前调用都有效
    // ftruncate(fd, size+sizeof(struct stu));
    // //映射到一个虚拟地址
    // s = mmap(0, size+sizeof(struct stu), PROT_READ|PROT_WRITE,
    //     MAP_SHARED, fd, 0);
    //把数据写入虚拟地址
    // printf("输入姓名：");
    // scanf("%s",s[count].name);
    // printf("输入年龄：");
    // scanf("%d",&s[count].age);
    // printf("输入成绩：");
    // scanf("%f",&s[count].score);
    s = mmap(0, size, PROT_READ|PROT_WRITE,
        MAP_SHARED, fd, 0);
    for(i=0; i < count; i++) {
        printf("%s,\t%d,\t%.2f\n",
            s[i].name, s[i].age, s[i].score);
    }
    //卸载虚拟地址
    munmap(s, sizeof(struct stu) + size);
    //关闭文件
    close(fd);
}
