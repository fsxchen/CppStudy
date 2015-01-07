#include <curses.h>
void init();
void drawUi();
void dealInput();

void destory();

int main() {
    init();
    drawUi();
    dealInput();
    destory();
}

void dealInput() {

    int a, b;
    while(1)
    {
        mvaddstr(2, 3, "     ");
        mvscanw(2, 3, "%d", &a);
        mvaddstr(2, 11, "     ");
        mvscanw(2, 11, "%d", &b);
        mvaddstr(2, 20, "      ");
        mvprintw(2, 20, "%d", a+b );
        refresh();
    }
}

void drawUi() {
    mvaddstr(2, 2,"[     ]+[     ]=[      ]");
    refresh();

}

void destory() {
    endwin();
}
void init() {
    initscr();
}
