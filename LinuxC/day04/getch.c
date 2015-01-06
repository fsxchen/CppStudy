#include <curses.h>
main() {
    //初始化
    int ch;
    initscr();
    //循环输入
    while(1) {
        ch=mvgetch(5, 10);
    //循环显示
        mvprintw(8, 10, "You input is:%c(%d)", ch, ch);
        refresh();
    }
    //释放
    endwin();
}
