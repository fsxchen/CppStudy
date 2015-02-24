#include "ThClient.h"
#include "ServerWindow.h"
#include <sys/socket.h>
#include <list>
#include <unistd.h>
using namespace std;

void ThClient::run() {
    int r;
    char buf[1024];
    while(true) {
        r = recv(fd, buf, sizeof(buf)-1, 0);
        if (r <=0) {
            //emit 客户退出
            emit sigInfo(tr("有客户退出"));
            ServerWindow::allusers.remove(this);
            close(fd);
            // delete this;
            break;
        }
        buf[r] = 0;
        //发送消息,把接收到的数据显示到服务器主窗体中
        emit sigInfo(tr(buf));
        //广播
        list<ThClient *>::iterator it = ServerWindow::allusers.begin();
        while(it != ServerWindow::allusers.end()) {
            send((*it)->fd, buf, strlen(buf), 0);
            it++;
        }
    }
}
