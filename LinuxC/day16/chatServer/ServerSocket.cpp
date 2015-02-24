#include "ServerSocket.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void ServerSocket::initSocket() throw(ChatException){
    struct sockaddr_in addr;
    int r;
    serfd = socket(AF_INET, SOCK_STREAM, 0);
    if(serfd == -1) throw ChatException("socket错误");
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);
    r = bind(serfd, (struct sockaddr*)&addr, sizeof(addr));
    if (r == -1) {
        close(serfd);
        throw ChatException("bind错误");
    }
    r = listen(serfd, 10);
    if (r == -1)  {
        close(serfd);
        throw ChatException("listen错误");
    }
}

int ServerSocket::accept() throw(ChatException) {
    int cfd;
    cfd = ::accept(serfd, NULL, 0);
    if(cfd == -1) throw ChatException("accept错误");
    return cfd;
}
