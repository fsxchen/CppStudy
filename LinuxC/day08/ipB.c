#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <linux/un.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

main() {
    int fd;
    int r;
    struct sockaddr_in addr = {0};
    //1.建立socket
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    //2.连接到指定的地址
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999);
    addr.sin_addr.s_addr = inet_addr("192.168.2.90");
    r = connect(fd, (struct sockaddr *)&addr, sizeof(addr));
    //3.发送数据
    r = write(fd, "Hello!Maomaochong", strlen("Hello!Maomaochong"));
    if(r == -1) printf("err write:%m\n");
    printf("write sucess");
    //4.关闭
    close(fd);
}
