#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

main() {
    int fd;
    struct sockaddr_in ad;
    char buf[102];
    int r;

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd == -1) printf("socket:%m\n"), exit(-1);

    ad.sin_family = AF_INET;
    ad.sin_port = htons(11111);
    ad.sin_addr.s_addr = inet_addr("127.0.0.1");


    while(1) {
        r = read(0, buf, sizeof(buf) - 1);
        if(r <= 0) break;
        buf[r] = 0;

        sendto(fd, buf, r, 0, (struct sockaddr *)&ad, sizeof(ad));
    }
}
