#include <curses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

WINDOW *wtime, *wnumb;

main() {
    initscr();
    wtime=derwin(stdscr, 3, 10, 0, (COLS-10));
    wnumb=derwin(stdscr, 3, 11, (LINES-3)/2, (COLS-11)/2);
    box(wtime, 0, 0);
    box(wnumb, 0, 0);
    refresh();
    wrefresh(wtime);
    wrefresh(wnumb);
    if(fork()) {
        //show time
        time_t tt;
        struct tm *t;
        while(1) {
            tt = time(0);
            t = localtime(&tt);
            mvwprintw(wtime, 1, 1, "%02d:%02d:%02d",
                t->tm_hour, t->tm_min, t->tm_sec);
            refresh();
            wrefresh(wtime);
            wrefresh(wnumb);
            sleep(1);
        }
    } else {
        //show number
        int num=0;
        int i;
        while(1) {
            // num = 0;
            // num = rand() % 1000000;
            for (i = 0; i < 7; i ++) {
                num = num*10 + rand()%10;
            }
            mvwprintw(wnumb, 1, 2, "%07d", num);
            refresh();
            wrefresh(wtime);
            wrefresh(wnumb);
            usleep(100000);
        }
    }

    endwin();
}
