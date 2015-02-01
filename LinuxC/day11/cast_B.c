#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

main() {
    int fd;
    int opt = 1;    //广播选项
    struct sockaddr_in dr;
    char buf[100];
    int r;

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd == -1) printf("socket err:%m\n"), exit(-1);
    r = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR,
        &opt, sizeof(opt));

    if(r == -1) printf("setsockopt err:%m\n"), exit(-1);

    printf("socket ok!\n");

    dr.sin_family = AF_INET;
    dr.sin_port = htons(9999);
    dr.sin_addr.s_addr = inet_addr("192.168.1.255");

    bind(fd, (struct sockaddr *)&dr, sizeof(dr));
    if(r == -1) printf("bind err:%m\n"), exit(-1);

    r = recv(fd, buf, 100, 0);
    if (r > 0) {
        buf[r] = 0;
        printf("接受的广播的数据是:%s\n", buf);
    }


}
