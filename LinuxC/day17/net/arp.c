#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/if_ether.h>
#include <linux/ip.h>

main() {
    int fd;
    char buf[2000];
    int r;
    struct ethhdr *eh;
    struct in_addr dr;
    struct iphdr *iph;

    fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    while(1) {
        r = read(fd, buf, 2000);
        eh = (struct ethhdr *)buf;
        printf("%02x:%02x:%02x:%02x:%02x:%02x\n", )
        printf("数据包的协议:%x\n", ntohs(eh->h_proto));
        if(ntohs(eh->h_proto) == 0x800) {
            iph = (struct iphdr *)(buf + 14);
            dr.s_addr = iph->saddr;
            printf("\t:%s\n", inet_ntoa(dr));
        }
    }
}
