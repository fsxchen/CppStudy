#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void init();
void drawLogin();
void destory();

main() {
    init();
    drawLogin();
    destory();
}

void drawLogin() {
    char *heads="XX Login System";
    char *user="UserName[        ]";
    char *pass="PassWord[        ]";
    box(stdscr, 0, 0);
    attron(A_BOLD);
    mvaddstr(3,(COLS-strlen(heads))/2, heads);
    mvhline(4,(COLS-strlen(heads))/2, 0, strlen(heads));
    attroff(A_BOLD);
    mvaddstr(8,(COLS-strlen(user))/2, user);
    mvaddstr(10,(COLS-strlen(pass))/2, pass);
    refresh();

}

void destory() {
    refresh();
    getch();
    endwin();
}

void init() {
    initscr();
}
