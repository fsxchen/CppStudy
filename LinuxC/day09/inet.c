#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

main() {
    in_addr_t nip = 192 << 24 | 168 << 16 | 1 << 8 | 100;
    char *ip = "192.168.1.100";
    char cip[4] = {192, 168, 1, 100};
    //1.把整数转换为字符串   inet_ntoa;
    struct in_addr sip = {nip};
    int myip;
    printf("%s\n", inet_ntoa(sip));

    myip = inet_addr(ip);
    printf("%u\n", myip);
    printf("%u.%u.%u.%u\n",
        myip >> 24 &255,
        myip >> 16 &255,
        myip >> 8 &255,
        myip >> 0 &255
        );
}
