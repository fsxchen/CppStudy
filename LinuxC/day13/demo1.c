#include <pthread.h>
#include <curses.h>
#include <math.h>

pthread_t t[26];
pthread_mutex_t m;

struct Achar {
    int x;
    int y;
    int speed;
    char a;
};

void * run(void *d) {
    int l;
    struct Achar a;
    l = *(int *)(d);
    a.x = rand() % COLS;
    a.y = rand() % (LINES / 4);
    a.speed = 1 + rand() % 3;
    a.a = 65 + rand() % 26;
    while(1) {
        //不停的改变对象的y坐标
        a.y += a.speed;
        if (a.y >= LINES) {
            a.y = rand() % (LINES/4);
        }
        //绘制到屏幕上
        pthread_mutex_lock(&m);
        mvaddch(a.y, a.x, a.a);
        //刷屏
        refresh();
        pthread_mutex_unlock(&m);
        //暂停
        usleep(10);
    }
}

main(){
    int i;
    initscr();
    pthread_mutex_init(&m, 0);
    for(i = 0; i < 26; i++) {
        //随机产生字母与位置

        pthread_create(&t[i], 0, run, &i);
    }
    getch();
    pthread_mutex_destroy(&m);
    endwin();
}
