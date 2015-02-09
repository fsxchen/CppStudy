#include "thyao.h"
#include <unistd.h>
#include <cmath>

void ThYao::control(bool b) {
    isstop = b;
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
            usleep(10000);
        }
    }
}
