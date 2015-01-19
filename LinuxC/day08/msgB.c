#include <unistd.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>

struct msgbuf {
    long type;
    char data[32];
};

main() {
    key_t key;
    int msgid;
    int i;
    //1.得到消息队列
    key = ftok(".", 200);
    if(key == -1) printf("ftok err:%m\n"), exit(-1);

    msgid = msgget(key, 0);
    if(msgid == -1) printf("msgget err:%m\n"), exit(-1);

    //2.构造消息
    struct msgbuf msg;
    //3.接受消息
    while(1) {
        bzero(&msg, sizeof(msg));
        msgrcv(msgid, &msg, sizeof(msg.data), 2, 0);
        printf("%s\n", msg.data);
    }
}
