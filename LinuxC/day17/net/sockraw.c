#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/udp.h>
#include <linux/tcp.h>
#include <linux/icmp.h>


int main() {
    int fd;
    char buf[2000];     //可以根据MTU设置
    struct iphdr *iph;
    struct tcphdr *tcph;
    struct icmphdr *icmp;
    int r;
    int isip=1;
    struct in_addr ddr;

    fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    setsockopt(fd, IPPROTO_IP, IP_HDRINCL, &isip, sizeof(int)); //让数据包含IP头

    while(1) {
        r = read(fd, buf, 2000);
        iph = (struct iphdr *)buf;
        ddr.s_addr=iph->saddr;
        printf("捕获到ip协议包:%d:%s\n", r, inet_ntoa(ddr));
        if (r <=0) break;
    }
}
