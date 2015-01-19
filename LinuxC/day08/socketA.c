#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/un.h>

main() {
    int fd;
    int r;
    char buf[200];
    //1.建立一个socket
    fd = socket(AF_UNIX, SOCK_DGRAM, 0);    //AF_UNIX, AF_INET   SOCK_STREAM, SOCK_DGRAM
    if(fd == -1) printf("socket err:%m\n"), exit(-1);
    printf("socket成功！\n");
    //2.构建本地文件地址
    struct sockaddr_un addr= {0};
    addr.sun_family = AF_UNIX;
    memcpy(addr.sun_path, "my.sock", strlen("my.sock"));

    //3.把socket绑定在地址上
    r = bind(fd, (struct sockaddr*)&addr, sizeof(addr));
    if(r == -1) printf("bind err:%m\n"), exit(-1);
    printf("地址绑定成功\n");
    // 4.接受数据
    bzero(buf, sizeof(buf));
    r = read(fd, buf, sizeof(buf));
    buf[r] = 0;
    printf("%s\n", buf);
    //5.关闭
    close(fd);
    //6.删除socket文件
    // printf("%d:%d\n", getpid(), fd);
    // while(1);
}
