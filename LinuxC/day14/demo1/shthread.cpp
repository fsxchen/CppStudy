#include "shthread.h"
#include <unistd.h>
#include <math.h>

ShakeThread::ShakeThread(QLineEdit *txt) {
    m_txt = txt;
}
void *ShakeThread::s_run(void *d) {
    ShakeThread *st = (ShakeThread*)d;
    st->run();
    return NULL;
}
void ShakeThread::start() {
    pthread_create(&tid, 0, s_run, this);
}

void ShakeThread::run() {
    //实现线程逻辑
    int num;
    while(1) {
        //修改文本框
        num = rand() % 10000000;
        m_txt->setText(QString::number(num));
        usleep(10000);
    }
}
