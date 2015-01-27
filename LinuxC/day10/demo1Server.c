#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

main() {
    int sfd, cfd, ffd;
    int r;
    int len;
    char buf[128];
    char filename[100];
    struct sockaddr_in saddr;

    //1.建立服务器socket
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sfd == -1) printf("1:%m\n"), exit(-1);
    printf("服务器socket创建成功！\n");
    //2.绑定IP地址
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9999);
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    r = bind(sfd, (struct sockaddr *)&saddr, sizeof(saddr));
    if(r == -1) printf("bind error:%m\n"), close(sfd), exit(-1);
    printf("绑定地址成功！\n");
    //3.listen
    r = listen(sfd, 10);
    if(r == -1) printf("listen error:%m\n"), close(sfd), exit(-1);
    printf("监听成功！\n");
    //4.accept
    cfd = accept(sfd, 0, 0);
    if(cfd == -1) printf("accept error:%m\n"), close(sfd), exit(-1);
    printf("开始接收文件！\n");
    //5.接收文件名
    r = recv(cfd, &len, sizeof(len), MSG_WAITALL);
    r = recv(cfd, filename, len, MSG_WAITALL);
    filename[len] = 0;
    printf("传递的文件名字是:%s\n", filename);
    //6.创建文件
    ffd = open("XXX.txt", O_RDWR | O_CREAT, 0666);
    //7.循环接收文件
    while(1) {
        r = recv(cfd, &len, sizeof(len), MSG_WAITALL);
        if(len == 0) break;
        r = recv(cfd, buf, len, MSG_WAITALL);

        write(ffd, buf, len);
    }
    close(ffd);
    close(cfd);
    close(sfd);
    printf("接收文件完毕\n");
}
