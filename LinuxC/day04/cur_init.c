#include <curses.h>
int main() {
    WINDOW *w = initscr();      //初始化终端
    // border(0, 0, 0, 0, 0, 0, 0, 0);
    box(stdscr,0, 0);
    mvhline(2, 10, '-', 20);
    mvvline(2, 10, '|', 20);
    refresh();
    getchar();      //等待一个字符输入
    endwin();       //释放终端
    return 0;
}
