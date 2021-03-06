#include "ServerWindow.h"
#include "chatException.h"
#include <QColor>
#include <QMessageBox>
list<ThClient *> ServerWindow::allusers;
ServerWindow::ServerWindow(QWidget *p) {
    //初始化窗体
    this->resize(1024, 768);
    this->move(0, 0);
    this->setWindowTitle(tr("聊天服务"));
    //初始化组件
    info = new QTextEdit;
    info->setTextColor(QColor(255, 0, 0));
    info->append(tr("欢迎使用聊天使用程序"));
    info->append(tr("=================="));
    info->setTextColor(QColor(0, 0, 0));
    info->setFontPointSize(20);

    this->setCentralWidget(info);
    //初始化菜单

    bar = new QMenuBar(this);
    mnuserver = new QMenu(tr("服务器"), bar);
    actstart = new QAction(tr("启动"), mnuserver);
    actexit = new QAction(tr("退出"), mnuserver);

    abtserver = new QMenu(tr("关于"), bar);

    //菜单组件的关系维护
    mnuserver->addAction(actstart);
    mnuserver->addSeparator();
    mnuserver->addAction(actexit);

    bar->addMenu(mnuserver);
    bar->addMenu(abtserver);
    this->setMenuBar(bar);

    //初始化状态条
    status = new QStatusBar(this);
    lbltip = new QLabel(tr("提示"), status);
    lblresult = new QLabel(tr("操作结果显示"), status);
    lbltime = new QLabel(tr("2010-11-24"), status);
    lbltime->setFrameShape(QFrame::Panel);

    //状态条关系维护
    status->addPermanentWidget(lbltip, 300);
    status->addPermanentWidget(lblresult, 500);
    status->addPermanentWidget(lbltime, 0);

    this->setStatusBar(status);

    connect(actstart, SIGNAL(triggered()), this, SLOT(onStart()));
    connect(actexit, SIGNAL(triggered()), this, SLOT(qtExit()));

    this->setVisible(true);
}

void ServerWindow::onStart() {
    // QMessageBox::information(this, tr("提示"), tr("响应"));
    try{
        thaccept.init();
        thaccept.info = info;
        info->setTextColor(QColor(0, 255, 0));
        info->append(tr("服务器启动成功!"));
        connect(&thaccept, SIGNAL(sigInfo(const QString &)),
            info, SLOT(append(const QString)));
        thaccept.start();
        info->append(tr("服务器接受线程成功!"));
    } catch(ChatException e) {
        info->setTextColor(QColor(255, 0, 0));
        info->append(tr(e.what()));
    }
}

void ServerWindow::qtExit() {
    QMessageBox::information(this, tr("提示"), tr("响"));
}
