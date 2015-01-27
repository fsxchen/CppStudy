#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

main() {
    int sfd;
    int ffd;
    int r;
    int size;
    int len;
    char buf[128];
    char filename[] = "udp_a.c";
    struct sockaddr_in addr;

    //1.建立socket
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sfd == -1) printf("socket error:%m\n"), exit(-1);
    printf("socket创建成功！\n");
    //2.连接到服务器
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999);
    inet_aton("127.0.0.1",&addr.sin_addr);
    r = connect(sfd, (struct sockaddr *)&addr, sizeof(addr));
    if(r == -1) printf("connect error:%m\n"), exit(-1);
    printf("connect成功！\n");
    //3.打开文件
    ffd = open(filename,O_RDONLY, 0);
    if(ffd == -1) printf("open error:%m\n"), exit(-1);
    printf("open文件成功！\n");

    //4.发送文件名
    len = strlen(filename);
    r = send(sfd, &len, sizeof(len), 0);    //发送文件名字
    r = send(sfd, filename, len, 0);        //发送文件名字
    if(r == -1) printf("send error:%m\n"), close(ffd), close(sfd), exit(-1);
    printf("发送文件名成功！\n");
    //5.循环发送数据
    while(1) {
        size = read(ffd, buf, 128);
        if(size == -1) break;
        if(size == 0) break;
        if(size > 0) {
            r = send(sfd, &size, sizeof(size), 0);    //发送的数据长度
            if(r == -1) break;
            r = send(sfd, buf, size, 0);       //发送数据
            if(r == -1) break;
        }
    }
    //6.读取到的文件尾，发送长度为0的数据包
    size = 0;
    r = send(sfd, &size, sizeof(size), 0);
    close(ffd);
    close(sfd);
    printf("OK!\n");
}
