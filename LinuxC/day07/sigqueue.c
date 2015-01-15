#include <stdio.h>
#include <signal.h>
#include <unistd.h>

main() {
    union sigval val;
    val.sival_int = 9999;

    sigqueue(10660, SIGUSR1, val);
}
