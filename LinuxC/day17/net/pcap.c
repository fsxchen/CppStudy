#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pcap/pcap.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
//获取当前可用的设备
int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev;
    dev = pcap_lookupdev(errbuf);
    if(dev == NULL) {
        printf("::%s\n", errbuf);
        exit(-1);
    }

    printf("%s\n", dev);
    return 0;
}
