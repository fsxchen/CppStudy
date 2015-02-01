#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

int fd, cfd;

void handle(int s) {
    if(s == SIGURG){
        char data[100];
        int r;
        r = recv(cfd, data, 100, MSG_OOB);
        data[r] = 0;
        printf("接受数据:%s\n", data);
    }
}

main() {

    struct sockaddr_in dr;
    char buf[100];
    int r;

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd == -1) printf("socket err:%m\n"), exit(-1);
    printf("socket ok!\n");

    dr.sin_family = AF_INET;
    dr.sin_port = htons(9999);
    dr.sin_addr.s_addr = inet_addr("192.168.1.2");

    bind(fd, (struct sockaddr *)&dr, sizeof(dr));
    if(r == -1) printf("bind err:%m\n"), exit(-1);
    printf("bind ok!\n");
    r = listen(fd, 10);
    if(r == -1) printf("listen err:%m\n"), exit(-1);
    printf("listen ok!\n");

    signal(SIGURG, handle);
    cfd = accept(fd, 0, 0);
    fcntl(cfd, F_SETOWN, getpid());
    if(cfd == -1) printf("listen err:%m\n"), exit(-1);
    printf("accept ok!\n");
    while(1) {
        r = recv(cfd, buf, 100, 0);
        // r = recv(cfd, buf, 100, MSG_OOB);

        if (r > 0) {
            buf[r] = 0;
            printf("接受的广播的数据是:%s\n", buf);
        }else {
            break;
        }
        // r = recv(cfd, buf, 100, 0);
        // r = recv(cfd, buf, 100, MSG_OOB);
        //
        // if (r > 0) {
        //     buf[r] = 0;
        //     printf("接受的广播的数据是:%s\n", buf);
        // }else {
        //     break;
        // }
    }
    close(cfd);
    close(fd);



}
