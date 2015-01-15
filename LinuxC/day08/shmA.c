#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/shm.h>
#include <sys/ipc.h>

main() {
    key_t key;
    int shmid;
    //1.创建共享内存shmget
    key = ftok(".", 255);
    if(key == -1) printf("ftok error:%m\n") , exit(-1);
    shmid = shmget(key, 4, IPC_CREAT| IPC_EXCL | 0666);
    if(shmid == -1) printf("shmget error:%m\n") , exit(-1);
    //2.挂载共享内存shmat
    //3.访问共享内存
    //4.卸载共享内存shmdt
    //5.删除共享内存shctl
}
