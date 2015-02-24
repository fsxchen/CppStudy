#include "ThAccept.h"
#include "ThClient.h"
#include <cstdio>
#include <cstdio>
#include "ServerWindow.h"
using namespace std;

void ThAccept::init() throw(ChatException){
    sprintf(server.ip, "127.0.0.1");
    server.port = 8888;
    try {
        server.initSocket();
    } catch(ChatException e) {
        throw e;
    }
}

void ThAccept::run() {
    while(true) {
        try {
            int fd = server.accept();
            //发出信号, 客户连接信号
            emit sigInfo(tr("有人连接!"));
            //建立子线程监听对应的客户端
            ThClient *th = new ThClient;
            th->fd = fd;
            connect(th, SIGNAL(sigInfo(const QString &)),
                info, SLOT(append(const QString &)));
            ServerWindow::allusers.push_back(th);
            th->start();

        } catch(ChatException e) {
            //发出信号,服务器崩溃信号
            emit sigInfo(tr("服务器崩溃!"));
            break;
        }
    }
}
