#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int mysort(const struct dirent **d1, const struct dirent **d2) {
    return -alphasort(d1, d2);
}

int myfilter(const struct dirent *d) {
    if(memcmp(d->d_name, ".", 1) == 0) return 0;
    else return -1;
}

int main() {
    struct dirent **d;
    int r;
    int i;
    r = scandir("/home/fsxchen", &d, myfilter, mysort);
    printf("子目录个数%d\n", r);
    for(i = 0; i < r; i++) {
        printf("%s\n", d[i]->d_name);
    }

    while(*d) {
        printf("%s\n", (*d)->d_name);
        d++;
    }

    return 0;
}
