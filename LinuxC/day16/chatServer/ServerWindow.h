#ifndef SERVER_WINDOW_H
#define SERVER_WINDOW_H
#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QStatusBar>
#include <QLabel>
#include <list>
#include "ThAccept.h"
#include "ThClient.h"

class ServerWindow:public QMainWindow {
Q_OBJECT
public:
    static list<ThClient *> allusers;  //静态成员需要在全局初始化
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

    //接受线程
    ThAccept thaccept;
public:
    ServerWindow(QWidget *p=NULL);
public slots:
    void onStart();
    void qtExit();
};

#endif
