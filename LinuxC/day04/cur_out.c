#include <curses.h>
int main() {
    initscr();

    box(stdscr, 0, 0);
    // mvaddch(2, 10, 'A'|A_BOLD|A_UNDERLINE);
    if(has_colors() == TRUE) {
        start_color();
        init_pair(1,COLOR_RED, COLOR_WHITE);
        init_pair(2,COLOR_BLUE, COLOR_GREEN);
        init_pair(3,COLOR_BLACK, COLOR_WHITE);
        bkgd(COLOR_PAIR(3));
    }
    mvaddch(2, 10, ACS_DARROW|COLOR_PAIR(1));
    mvaddch(3, 10, ACS_PI|COLOR_PAIR(2));

    attron(COLOR_PAIR(1)|A_UNDERLINE);
    mvaddstr(4, 10, "Hello ");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvaddstr(6, 10, "Hello XXXXX");
    attroff(COLOR_PAIR(2));

    mvprintw(9, 10, "行:%d, 列:%d", LINES, COLS);

    refresh();
    getchar();
    endwin();
}
