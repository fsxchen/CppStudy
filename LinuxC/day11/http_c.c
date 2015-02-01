#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int fd;
    struct sockaddr_in dr;
    char strreq[1024];
    char buf[4096];
    int r;

    //建立socket
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd == -1) printf("socket err:%m\n"), exit(-1);
    //连接服务器x.x.x.x
    dr.sin_family = AF_INET;
    dr.sin_port = htons(8000);
    dr.sin_addr.s_addr = inet_addr("192.168.1.2");
    r = connect(fd, (struct sockaddr *)&dr, sizeof(dr));
    //构建http请求字符串
    sprintf(strreq,
        "GET /socket5.py HTTP/1.1\r\n"
        "Host: 192.168.12.:8000"
        "User-Agent: Mozilla/5.0\r\n"
        "Accept: text/html,application/xhtml+xml,application/xml\r\n"
        "Accept-Language: zh-CN,zh\r\n"
        "Accept-Charset: utf-8\r\n"
        "Keep-Alive: 300\r\n"
        "Connection: keep-alive\r\n"
        "\r\n");
    //发送http请求字符串
    r = send(fd, strreq, strlen(strreq), 0);
    //等待服务器的响应
    while(1) {
        r = recv(fd, buf, 1024, 0);
        if(r <= 0) break;
        printf("======================\n");
        printf("%s\n", buf);
        printf("======================\n");
    }
    printf("Over!\n");
    close(fd);

}
