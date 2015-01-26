#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

main() {
    int serfd;
    int cfd;
    int r;
    socklen_t len;
    struct sockaddr_in saddr, caddr;
    //1.socket
    serfd = socket(AF_INET, SOCK_STREAM, 0);
    if(serfd == -1) printf("1:%m\n"), exit(-1);
    printf("建立服务器socket成功！\n");
    //2.bind
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9999);
    inet_aton("192.168.2.205", &saddr.sin_addr);
    r = bind(serfd, (struct sockaddr *)&saddr, sizeof(saddr));
    if(r == -1) printf("2:%m\n"), exit(-1);
    printf("服务器地址绑定成功！\n");
    //3.listen
    r = listen(serfd, 10);
    if(r == -1) printf("3:%m\n"), exit(-1);
    printf("监听服务器成功!\n");
    //4.accept
    while(1) {
        len = sizeof(caddr);
        cfd = accept(serfd, (struct sockaddr *)&caddr, &len);
        printf("有人连接:%d, IP:%s:%u\n",
            cfd, inet_ntoa(caddr.sin_addr), ntohs(caddr.sin_port));
    }

}
