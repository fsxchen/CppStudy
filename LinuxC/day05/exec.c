#include <stdio.h>
#include <unistd.h>

int main() {
    int r = execl("/bin/ls", "ls", 0);    //表示命令行以0结尾
    // int r = execl("test", "test", "hello", 0);
    printf("结束:%d\n", r);
    return 0;
}
