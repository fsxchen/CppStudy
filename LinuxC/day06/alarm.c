#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void deal(int s) {
    printf("起床\n");
}
int main() {
    struct itimerval v={0};

    signal(SIGALRM, deal);
    // alarm(5);
    v.it_value.tv_sec = 3;
    // v.it_value.tv_sec = 0;
    // v.it_value.tv_usec = 1;  如果想立即输出，可以这样处理，一定不能是全0
    v.it_interval.tv_sec = 1;

    setitimer(ITIMER_REAL, &v, 0);
    while(1) {

    }
}
