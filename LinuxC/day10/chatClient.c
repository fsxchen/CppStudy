#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <curses.h>

WINDOW *winfo, *wmsg;
int fd;
int r;
struct sockaddr_in dr;

int initSocket();
void initUI();
void destory();

int main() {
    fd = initSocket();
    if(fd == -1) printf("socket err:%m\n"), exit(-1);
    printf("网络初始化成功！\n");
    initUI();
    if(fork()) {    //父进程
        //输入，发送
        char buf[256];
        while(1) {
            mvwgetstr(wmsg, 1, 1, buf);
            r = send(fd, buf, strlen(buf), 0);
            if(r == -1) printf("11111%m\n");
            wclear(wmsg);
            box(wmsg, 0, 0);
            refresh();
            wrefresh(wmsg);
        }

    } else {
        //接收显示
        char buf[256];
        int line = 1;
        while(1) {
            r = recv(fd, buf, 255, 0);
            buf[r] = 0;
            mvwaddstr(winfo, line, 1, buf);
            line++;
            if(line >= (LINES - 3)) {
                wclear(winfo);
                line = 1;
                box(winfo, 0, 0);
            }
            refresh();
            wrefresh(winfo);
            wmove(wmsg, 1, 1);
            touchwin(wmsg);
        }
    }

    destory();
    return 0;
}

void destory() {
    close(fd);
    endwin();
}

void initUI() {
    initscr();
    winfo = derwin(stdscr, (LINES-3), COLS, 0, 0);
    wmsg = derwin(stdscr, 3, COLS, LINES-3, 0);
    box(winfo, 0, 0);
    box(wmsg, 0, 0);
    refresh();
    wrefresh(winfo);
    wrefresh(wmsg);
}

int initSocket() {
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd==-1) return -1;
    dr.sin_family = AF_INET;
    dr.sin_port = htons(9999);
    dr.sin_addr.s_addr = inet_addr("127.0.0.1");
    r = connect(fd, (struct sockaddr *)&dr, sizeof(dr));
    if(r == -1) {
        close(fd);
        return -1;
    } else {
        return fd;
    }
}
