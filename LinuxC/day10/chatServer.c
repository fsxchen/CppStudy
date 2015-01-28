#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/mman.h>

int sfd;

int *fds; //存放客户所有的代理fd
int idx = 0;        //客户在数组中的下标
struct sockaddr_in dr;
int r;

main() {
    //1.建立服务器socket
    fds = mmap(0, 4*100, PROT_READ|PROT_WRITE,
        MAP_ANONYMOUS | MAP_SHARED, 0, 0);  //使用共享内存
    bzero(fds, sizeof(fds));
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sfd == -1) printf("socket err:%m\n"), exit(-1);
    printf("socket ok!\n");
    //2.绑定地址
    dr.sin_family = AF_INET;
    dr.sin_port = htons(9999);
    dr.sin_addr.s_addr = inet_addr("127.0.0.1");
    r = bind(sfd, (struct sockaddr *)&dr, sizeof(dr));
    if(r == -1) printf("bind err:%m\n"), close(sfd), exit(-1);
    printf("bind ok\n");
    //3.listen
    r = listen(sfd, 10);
    if(r == -1) printf("listen err:%m\n"), close(sfd), exit(-1);

    //4.循环accept
    while(1) {
        fds[idx] = accept(sfd, 0, 0);
        if(fds[idx] == -1) break;
        printf("有客户连接：%d\n", fds[idx]);
            //5.得到一个客户，建立一个子进程
        if(fork()) {
            idx++;
            continue;
        } else {
            //6.子进程任务：接收客户数据，并且广播
            char buf[256];
            int i;
            while(1) {
                //接收客户数据
                r = recv(fds[idx], buf, 255, 0);
                if(r == 0) {
                    printf("有客户退出！\n");
                    close(fds[idx]);
                    fds[idx] = 0;
                    break;
                }
                if(r == -1) {
                    printf("网络故障！\n");
                    close(fds[idx]);
                    fds[idx] = 0;
                    break;
                }
                buf[r] = 0;
                printf("来自客户的数据：%s\n", buf);
                for(i = 0; i < 100; i++){
                    if(fds[i] > 0) {
                        send(fds[i], buf, r, 0);
                    }
                }
            }
            exit(0);
        }
    }
    close(sfd);
}
