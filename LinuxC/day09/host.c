#include <stdio.h>
#include <netdb.h>
main() {
    struct hostent *ent;
    //打开主机配置数据库文件
    sethostent(1);//1.表示一直连接


    while(1) {
        ent = gethostent();
        if(ent == 0) break;

        printf("主机名：%s\t", ent->h_name);
        printf("IP地址：%hhu.%hhu.%hhu.%hhu\n", ent->h_addr[0],
            ent->h_addr[1],
            ent->h_addr[2],
            ent->h_addr[3]);
    }
    endhostent();
}
