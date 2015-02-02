#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>

void call() {
    pthread_exit("Kill");
    return;
}

void * run(void *data) {
    while(1) {
        printf("我是线程！%s\n", data);
        sched_yield();      //放弃优先执行
        // return "Hello";
        pthread_exit("world");
    }
}

main() {
    pthread_t tid;
    char *re;
    pthread_create(&tid, 0, run, (void *)"Jack");
    // sleep(1);
    pthread_join(tid, (void **)&(re));
    printf("%s\n", re);
}
