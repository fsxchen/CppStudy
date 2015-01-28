#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

main() {
    int fd;
    int r;
    int i;

    struct sockaddr_in addr;
    //1.socket
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd == -1) printf("1:%m\n"), exit(-1);
    printf("建立socket成功！\n");
    //2.connect
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999);
    inet_aton("192.168.2.205", &addr.sin_addr);
    r = connect(fd, (struct sockaddr *)&addr, sizeof(addr));
    if(r == -1) printf("2:%m\n"), exit(-1);
    printf("连接服务器成功！\n");

    for(i = 0; i <20 ; i++) {
        send(fd, "hello", 5, 0);
        // if(r == 0) {
        //     printf("连接断开！\n");
        //     break;
        // }
        // if(r == -1) {
        //     printf("网络断开！\n");
        //     break;
        // }
    }
}