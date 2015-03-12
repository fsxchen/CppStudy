#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pcap/pcap.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//获取当前可用的设备

void handle(u_char *user,           //pcap_loop的参数的最后一个值
    const struct pcap_pkthdr *h,    //接收到的数据报的大小
    const u_char *bytes){            //接收的数据报

    struct iphdr * iph;
    struct in_addr dr;
    if(h->len > 14) {
        printf("有ip数据报！\n");
        iph = (struct iphdr *)(bytes + 14);
        dr.s_addr = iph->saddr;
        printf("\t:%s\n", inet_ntoa(dr));
    } else {
        printf("有arp数据报！\n");
    }
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev;
    pcap_t *h;  //  监听设备的句柄(描述符号)
    struct bpf_program fp;
    int r;

    dev = pcap_lookupdev(errbuf);
    if(dev == NULL) {
        printf("::%s\n", errbuf);
        exit(-1);
    }

    printf("%s\n", dev);

    h = pcap_open_live(dev,     //打开的设备名称
                        200,    //捕获数据报的大小
                        0,      //是否使用混杂模式
                        1000,   //延时1s
                        errbuf);//如果有错误，返回错误
    if(h == NULL) {
        printf("err:%s\n", errbuf);
        exit(-1);
    }
    printf("打开设备成功！\n");
    r = pcap_compile(h,     //设备(句柄)
                    &fp,    //规则的返回值结构体
                    NULL,   //规则，可以指定 "tcp"/"ip"/"arp",NULL表示抓取全部
                    1,      //优化
                    0);     //网络掩码
    if(r == -1) {
        printf("::%s\n", pcap_geterr(h));
        exit(-1);
    }
    printf("编译规则成功！\n");

    r = pcap_setfilter(h, &fp);
    if(r == -1) {
        printf("::%s\n", pcap_geterr(h));
        exit(-1);
    }
    printf("设置过滤规则成功！\n");

    r = pcap_loop(h,
                0,         //函数返回前，处理的最大数据报， 0， -1表示处理所有数据
                handle,           //收到数据包后的回调函数
                NULL       //传递给回调函数的第一个参数
                );

    return 0;
}
