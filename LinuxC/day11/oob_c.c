#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

main() {
    int fd;
    struct sockaddr_in dr;
    char buf[100];
    int r;

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd == -1) printf("socket err:%m\n"), exit(-1);
    printf("socket ok!\n");

    dr.sin_family = AF_INET;
    dr.sin_port = htons(9999);
    dr.sin_addr.s_addr = inet_addr("192.168.1.2");

    r = connect(fd, (struct sockaddr *)&dr, sizeof(dr));
    if(r == -1) printf("connect err:%m\n"), exit(-1);
    printf("connect ok!\n");
    // send(fd, "Hello", 5, 0);

    while(1) {
        send(fd, "Hello", 5, MSG_OOB);
        sleep(1);
    }
    close(fd);



}
