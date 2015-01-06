#include <curses.h>
#include <time.h>
#include <unistd.h>
void init();
void drawui();
void business();
void destroy();
main() {
    init();
    drawui();
    business();
    destroy();
}

void business() {
    time_t tt;
    struct tm *t;
    while(1) {
        //取时间
        tt = time(0);
        t=localtime(&tt);
        //显示时间
        mvprintw(LINES/2, (COLS-8)/2, "%02d:%02d:%02d",
            t->tm_hour, t->tm_min, t->tm_sec);
        //刷新屏幕
        refresh();
        sleep(1);
    }
}
void drawui() {
    box(stdscr, 0, 0);
}

void init() {
    initscr();
}

void destroy() {
    endwin();
}
