#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int r;
    int fd;
    int count;
    int i;
    struct ifreq ir[10];    //返回网络接口的存储缓冲
    struct ifconf cf;
    cf.ifc_len = sizeof(ir);
    cf.ifc_req = ir;

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    r = ioctl(fd, SIOCGIFCONF, &cf);

    //返回结构的个数
    count = cf.ifc_len/sizeof(struct ifreq);

    printf("返回的接口的个数:%u\n", count);
    //循环打印接口信息
    for (i = 0; i < count; i++) {
        printf("%s\n", ir[i].ifr_name);
        struct ifreq rr, re;
        struct sockaddr_in *ddr;
        memcpy(rr.ifr_name, ir[i].ifr_name, strlen(ir[i].ifr_name));
        //返回接口的参数
        r = ioctl(fd, SIOCGIFDSTADDR, &rr);
        ddr = (struct sockaddr_in *)&rr.ifr_dstaddr;
        printf("\t|-%s\n", inet_ntoa(ddr->sin_addr));

        r = ioctl(fd, SIOCGIFBRDADDR, &re);
        ddr = (struct sockaddr_in *)&re.ifr_broadaddr;
        printf("\t|-%s\n", inet_ntoa(ddr->sin_addr));
    }

    return 0;
}
