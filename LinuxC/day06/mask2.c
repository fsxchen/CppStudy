#include <stdio.h>
#include <signal.h>

void h(int s) {
    printf("抽空处理int信号\n");
}

main() {
    int sum = 0;
    int i;
    //1.声明
    signal(SIGINT, h);

    for(i = 1; i <= 10; i++) {
        sum += i;

        sleep(1);
    }
    printf("sum=%d\n", sum);
    printf("over!\n");
}
