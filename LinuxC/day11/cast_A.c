#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

main() {
    int r;
    int fd;
    int opt = 1;    //广播选项
    struct sockaddr_in dr;

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd == -1) printf("socket err:%m\n"), exit(-1);
    r = setsockopt(fd, SOL_SOCKET, SO_BROADCAST,
        &opt, sizeof(opt));

    if(r == -1) printf("setsockopt err:%m\n"), exit(-1);

    printf("socket ok!\n");

    dr.sin_family = AF_INET;
    dr.sin_port = htons(9999);
    dr.sin_addr.s_addr = inet_addr("192.168.1.255");

    r = sendto(fd, "Hello", 5, 0, (struct sockaddr *)&dr,
        sizeof(dr));
    if(r == -1) printf("send err:%m\n"), exit(-1);
    close(fd);
}
