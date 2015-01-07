#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

int main() {
    DIR *d;
    struct dirent *de;
    //打开一个目录
    d = opendir("/home/fsxchen");
    if(d == 0) {
        printf("opendir:%m\n");
        exit(-1);
    }
    //循环读取目录
    while((de = readdir(d)) != NULL) {
        printf("%s,\t%d\n", de->d_name, de->d_type);
    }
    //关闭目录
    closedir(d);
}
