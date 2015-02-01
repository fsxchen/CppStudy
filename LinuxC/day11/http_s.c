#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>


main() {

    int fd, cfd;
    struct sockaddr_in dr;
    char buf[100];
    int r;

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd == -1) printf("socket err:%m\n"), exit(-1);
    printf("socket ok!\n");

    dr.sin_family = AF_INET;
    dr.sin_port = htons(9999);
    dr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(fd, (struct sockaddr *)&dr, sizeof(dr));
    if(r == -1) printf("bind err:%m\n"), exit(-1);
    printf("bind ok!\n");
    r = listen(fd, 10);
    if(r == -1) printf("listen err:%m\n"), exit(-1);
    printf("listen ok!\n");

    cfd = accept(fd, 0, 0);
    fcntl(cfd, F_SETOWN, getpid());
    if(cfd == -1) printf("listen err:%m\n"), exit(-1);
    printf("accept ok!\n");
    while(1) {
        r = recv(cfd, buf, 1024, 0);
        // r = recv(cfd, buf, 100, MSG_OOB);

        if (r > 0) {
            buf[r] = 0;
            printf("::%s\n", buf);
        }else {
            break;
        }
    }
    close(cfd);
    close(fd);



}
