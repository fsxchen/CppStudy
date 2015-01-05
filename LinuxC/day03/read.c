#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main() {
    char name[20];
    short age;
    float score;
    char sex;
    int fd;
    int r;
    fd = open("test.dat", O_RDONLY);
    if(fd == -1) printf("open error:%m\n"), exit(-1);

    while(1) {
        r = read(fd, name, sizeof(name));
        if(r==0) break;
        r=read(fd, &age, sizeof(short));
        r=read(fd, &score, sizeof(float));
        r=read(fd, &sex, sizeof(sex));
        printf("%s,\t%4hd,\t%.2f,\t%1c\n",
            name,age,score,sex);
    }
    close(fd);
}
