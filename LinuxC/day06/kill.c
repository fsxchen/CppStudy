#include <stdio.h>
#include <signal.h>

int main() {
    while(1) {
        kill(2284, SIGINT);
        sleep(2);
    }
}
