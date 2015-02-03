#include <stdio.h>
#include <pthread.h>
#include <signal.h>

/*使用条件量达到两个线程的同步*/

pthread_t t1, t2;
pthread_cond_t cond;
pthread_mutex_t m;
void handle(int s) {

}

void * r1(void *d) {
    int s;
    while(1) {
        pthread_cond_wait(&cond, &m);
        printf("活动！\n");
    }
}

void * r2(void *d) {
    while(1) {
        sleep(1);
        pthread_cond_signal(&cond);
    }
}

main() {
    // signal(34, handle);
    pthread_mutex_init(&m, 0);
    pthread_cond_init(&cond, 0);

    pthread_create(&t1, 0, r1, 0);
    pthread_create(&t2, 0, r2, 0);
    pthread_join(t1, (void **)0);
    pthread_join(t2, (void **)0);

    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&m);

}
