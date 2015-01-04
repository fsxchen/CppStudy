#include <stdio.h>
#include <unistd.h>
int main() {
    // printf("%d\n", getpid());
    // while(1);
    // write(0, "Hello\n", 6);
    // write(1, "world\n", 6);
    // write(2, "Loise\n", 6);
    // int a=97;
    // write(1,&a, 4);
    char buf[32];
    int r = read(0, buf, 30);
    if (r > 0) {
        printf("实际输入%d\n", r);

        buf[r] = 0;
        // memset(buf, 0, 32);
        // bzero(buf, 32);
        printf("::%s\n", buf);
    }
    if (r == 0) {
        printf("ctrl-D\n");
    }
    if (r == -1) {
        printf("错误了啊!\n");
    }
}
