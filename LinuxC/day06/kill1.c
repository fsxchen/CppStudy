#include <stdio.h>
#include <signal.h>

int main() {
    // while(1) {
    int i;
    for(i = 0; i < 5; i++){
        kill(9127, 35);
    }
}
