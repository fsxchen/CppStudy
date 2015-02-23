#include "ServerWindow.h"
ServerWindow::ServerWindow(QWidget *p) {
    this->resize(1024, 768);
    this->move(0, 0);
    this->setWindowTitle(tr("聊天服务"));
    info = new QTextEdit;
    this->setCentralWidget(info);
    this->setVisible(true);
}
