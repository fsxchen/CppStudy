#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
// #include <sched.h>
pthread_t todd, tevent;

sigset_t sigs;
void handle(int s) {
    printf("%d\n", s);
}

void* runodd(void *d) {
    int i;
    int s;
    for(i = 0;; i+=2) {
        printf("%d\n", i);
        pthread_kill(tevent, 34);
        // sched_yield();
        sigwait(&sigs, &s);
    }
}

void* runeven(void *d) {
    int i;
    int s;
    for(i = 1;; i+=2) {
        printf("%d\n", i);
        // sched_yield();
        pthread_kill(todd, 34);
        sigwait(&sigs, &s);
    }
}

main() {
    signal(34, handle);
    sigemptyset(&sigs);
    sigaddset(&sigs, 34);
    pthread_create(&todd, 0, runodd, 0);
    pthread_create(&tevent, 0, runeven, 0);
    pthread_join(todd, (void**)0);
    pthread_join(tevent, (void**)0);

}
