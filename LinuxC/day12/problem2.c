#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t m;
void handle(void *d) {
    pthread_mutex_unlock(&m);
    printf("调用!!!!\n");
}

void* runodd(void *d) {
    int i;
    for(i = 1;; i+=2) {
        pthread_cleanup_push(handle, 0);    //在锁定期间调用pthread_exit()/pthread_cancel()以及
                                            //+任何期间pthread_cleanup_pop参数为1都会触发这个函数回调
        pthread_mutex_lock(&m);
        // sleep(1);

        printf("%d\n", i);
        // if(i > 100000)
        //     pthread_exit(0);     //另外一个会死锁
        // pthread_mutex_unlock(&m);
        // pthread_cleanup_pop(0);
        pthread_cleanup_pop(1);
    }
}

void* runeven(void *d) {
    int i;
    for(i = 0;; i+=2) {
        pthread_cleanup_push(handle, 0);
        pthread_mutex_lock(&m);
        // sleep(1);
        printf("%d\n", i);
        // pthread_mutex_unlock(&m);
        // pthread_cleanup_pop(0);
        pthread_cleanup_pop(1);
    }
}

main() {
    pthread_t todd, tevent;
    pthread_mutex_init(&m, 0);
    pthread_create(&todd, 0, runodd, 0);
    pthread_create(&tevent, 0, runeven, 0);
    sleep(5);
    pthread_cancel(todd);
    pthread_join(todd, (void**)0);
    pthread_join(tevent, (void**)0);
    pthread_mutex_destroy(&m);

}
