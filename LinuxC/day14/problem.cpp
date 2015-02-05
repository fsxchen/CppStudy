#include <stdio.h>
#include <unistd.h>
/*升级日志模块*/
void log() {
    //1.在原来的基础上修改
    // printf("日志输出ing！\n");
    printf("日志输出ing------V2！\n");
}
//2.添加一个新的函数
void log2() {
    printf("日志输出ing------V2！\n");
}

void biz() {
    while(1) {
        sleep(1);
        printf("我在处理业务！\n");
        log();
    }
}

void biz(void(*p)()) {
    while(1) {
        sleep(1);
        printf("我在处理业务！\n");
        p();
    }
}

int main() {
    biz(log2);
}
