#include "thyao.h"
#include <unistd.h>
#include <cmath>
#include <cstdio>

void ThYao::control(bool b) {
    isstop = b;
    printf("I get it isstop: %d\n", isstop);
}

ThYao::ThYao():isstop(false) {

}

void ThYao::run() {
    int num; {
        while(1){
            while(isstop);
            num=rand()%10000000;
            QString strnum=QString::number(num);
            emit number(strnum);
            usleep(100000);
        }
    }
}
