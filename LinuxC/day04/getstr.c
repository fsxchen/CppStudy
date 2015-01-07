#include <curses.h>
main() {
    char name[9];
    initscr();
    box(stdscr, 0, 0);
    //绘制界面
    mvaddstr(4, 10, "User三:[        ]");
    //输入
    int r = mvgetnstr(4, 16, name, 8);
    // name[r] = 0;
    //打印输入
    mvprintw(7, 10, "You shuru de shi:%s", name);
    //输入字符
    getch();
    refresh();
    endwin();
}
