#include <pthread.h>
#include <curses.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
// 全局变量两个窗体
WINDOW *wtime, *wnumb;
pthread_t thnumb, thtime;
// 线程1：随机数
//     循环产生7位随机数
//     显示
//     刷新

void *runnumb(void *d) {
    int num;
    while(1) {
        num = rand() %10000000;
        mvwprintw(wnumb, 1, 2, "%07d", num);
        refresh();
        wrefresh(wnumb);
        usleep(10000);
    }
    return 0;
}

// 线程2：时间
//     循环取时间
//     显示
//     刷新

void *runtime(void *d) {
    time_t tt;
    struct tm *t;
    while(1) {
        tt = time(0);
        t = localtime(&tt);
        mvwprintw(wtime, 1, 1, "%02d:%02d:%02d",
            t->tm_hour, t->tm_min, t->tm_sec);
        refresh();
        wrefresh(wtime);
        sleep(1);
    }
    return 0;
}

main() {
    //初始化curses界面
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    wnumb = derwin(stdscr, 3, 11, (LINES-3)/2, (COLS-11)/2);
    wtime = derwin(stdscr, 3, 10, 0, COLS-10);
    box(wnumb, 0, 0);
    box(wtime, 0, 0);
    refresh();
    wrefresh(wnumb);
    wrefresh(wtime);
    // 创建线程1
    pthread_create(&thnumb, 0, runnumb, 0);
    // 创建线程2
    pthread_create(&thtime, 0, runtime, 0);
    // 等待按键getch
    getch();

    // 结束
    delwin(wnumb);
    delwin(wtime);
    endwin();
}
