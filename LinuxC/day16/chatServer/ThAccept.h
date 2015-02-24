#ifndef TH_ACCEPT_H
#define TH_ACCEPT_H
#include <QThread>
#include "chatException.h"
#include "ServerSocket.h"
#include <QTextEdit>
class ThAccept:public QThread {
Q_OBJECT
public:
    QTextEdit *info;
private:
    ServerSocket server;
public:
    void init() throw(ChatException);
    void run();     //在线程中接收客户的联接
public:signals:
    void sigInfo(const QString &);
};
#endif
