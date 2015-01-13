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
    sigset_t sigs, sigp, sigq;
    sigemptyset(&sigs);
    sigemptyset(&sigp);
    sigemptyset(&sigq);

    sigaddset(&sigs, SIGINT);
    sigprocmask(SIG_BLOCK, &sigs, 0);

    for(i = 1; i <= 10; i++) {
        sum += i;
        sigpending(&sigp);
        if(sigismember(&sigp, SIGINT)) {
            printf("SIGINT信号在排队\n");
            sigsuspend(&sigq);  //这里等待信号处理，这么写的好处。你可以控制信号中断的位置
                                //+代码必须在这里中断。
            //使原来屏蔽信号无效，开放原来信号
            //使新的信号屏蔽,
            //当某个信号处理函数处理完毕
            //sigsuspend恢复原来屏蔽信号，返回
        }
        sleep(1);
    }
    printf("sum=%d\n", sum);
    sigprocmask(SIG_UNBLOCK, &sigs, 0);
    printf("over!\n");
}
