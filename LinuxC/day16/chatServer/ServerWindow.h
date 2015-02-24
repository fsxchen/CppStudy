#ifndef SERVER_WINDOW_H
#define SERVER_WINDOW_H
#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QStatusBar>
#include <QLabel>

class ServerWindow:public QMainWindow {
private:
    QTextEdit   *info;
    //菜单
    QMenuBar    *bar;

    QMenu       *mnuserver;
    QMenu       *abtserver;

    QAction     *actstart;
    QAction     *actexit;
    //状态条
    QStatusBar  *status;

    QLabel      *lbltip;
    QLabel      *lblresult;
    QLabel      *lbltime;

public:
    ServerWindow(QWidget *p=NULL);
};

#endif
