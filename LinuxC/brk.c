#include <unistd.h>
#include <stdio.h>

main() {
    /*
    int *p = sbrk(4);       //分配4个字节的空间
    *p = 8888;
    printf("%d\n", *p);
    */
    // int *p=sbrk(0);         //返回虚拟地址首地址，没有虚拟映射
    // brk(p+1);               //错，没有映射
    // *p=8888;
    // brk(p);
    // *p=999;
    // int *p1=sbrk(4);     //返回空闲首地址，并修改指针位置+size
    // int *p2=sbrk(4);
    // int *p3=sbrk(4);
    // int *p4=sbrk(4);
    // int *p5=sbrk(4);

    // printf("%p\n", p1);
    // printf("%p\n", p2);
    // printf("%p\n", p3);
    // printf("%p\n", p4);
    // printf("%p\n", p5);

    // int *p1=sbrk(4);
    // int *p2=sbrk(200);
    // int *p3=sbrk(-4);
    // int *p4=sbrk(-4);
    // int *p5=sbrk(-4);
    // *(p1+1023)=8888;
    // // *(p1+1024) = 9999;   段错误，因为访问到了下一页
    // printf("%p\n", p1);
    // printf("%p\n", p2);
    // printf("%p\n", p3);
    // printf("%p\n", p4);
    // printf("%p\n", p5);
    // printf("%d\n", getpid());
    int *p=sbrk(0);
    brk(p+1);       //绝对移动
    *p=999;
    brk(p);
    *p=888;         //段错误，因为已经释放了

    while(1);
}
