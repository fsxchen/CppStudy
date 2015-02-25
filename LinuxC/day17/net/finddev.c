#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pcap/pcap.h>
//int pcap_findalldevs(pcap_if_t **alldevsp, char *errbuf);

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *it;
    int r;

    r = pcap_findalldevs(&it, errbuf);
    if(r == -1) {
        printf("err:%s\n", errbuf);
        exit(-1);
    }
    while(it) {
        printf(":%s\n", it->name);
        it = it->next;
    }

    return 0;
}
