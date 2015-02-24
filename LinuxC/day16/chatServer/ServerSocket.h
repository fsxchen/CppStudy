#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H
#include <QObject>
#include "chatException.h"

class ServerSocket: public QObject {
public:
    char ip[30];
    short port;
    int serfd;

public:
    void initSocket() throw (ChatException);
    int accept() throw(ChatException);
};

#endif
