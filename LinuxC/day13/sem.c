#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t sem;  //定义信号量
void * run(void *d) {
    while(1) {
        //3.剑操作
        sem_wait(&sem);
        printf("解除\n");
    }
}

main() {
    pthread_t tid;
    sem_init(&sem, 0, 5);   //初始化信号量
    pthread_create(&tid, 0, run, 0);

    while(1) {
        sleep(1);
        sem_post(&sem);
    }

}
