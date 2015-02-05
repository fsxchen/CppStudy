#ifndef SHAKE_THREAD_H
#define SHAKE_THREAD_H
#include <pthread.h>
#include <QLineEdit>
class ShakeThread {
private:
    pthread_t tid;
    static void *s_run(void *);
    QLineEdit *m_txt;
public:
    ShakeThread(QLineEdit *txt);
    virtual void run();
    void start();
};

#endif
