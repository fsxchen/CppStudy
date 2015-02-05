#ifndef SHAKE_THREAD_H
#define SHAKE_THREAD_H
#include <pthread.h>
#include <QLineEdit>
class ShakeThread :public QObject{
Q_OBJECT
private:
    pthread_t tid;
    static void *s_run(void *);
public:
    ShakeThread();
    virtual void run();
    void start();
public:signals:
    void setNumber(QString);
};

#endif
