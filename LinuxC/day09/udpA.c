#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

main() {
    int fd;
    struct sockaddr_in addr;    //本机的ip地址
    char buf[100];                  //接收数据的缓冲
    struct sockaddr_in addr_sender; //发送者的IP地址
    socklen_t len;        //发送者IP的长度
    int r;

    fd = socket(AF_INET, SOCK_DGRAM, 17);
    if(fd == -1) printf("socket:%m\n"), exit(-1);
    printf("建立socket成功\n");

    addr.sin_family = AF_INET;
    addr.sin_port = htons(11111);
    inet_aton("192.168.2.205", &addr.sin_addr);

    r = bind(fd, (struct sockaddr*)&addr, sizeof(addr));
    if(r == -1) printf("bind err:%m\n"), exit(-1);
    printf("绑定成功！\n");

    while(1) {
        len = sizeof(addr_sender);
        r = recvfrom(fd, buf, sizeof(buf) -1, 0,
            (struct sockaddr *)&addr_sender, &len);
        if(r > 0) {
            buf[r] = 0;
            printf("发送者IP:%s, 数据:%s\n",
                inet_ntoa(addr_sender.sin_addr), "SS");
        }
        if(r == 0){ //表示连接被关闭了
            printf("关闭！\n");
            break;

        if(r == -1) {
            printf("网络故障");
            break;
        }
    }
    close(fd);


}
