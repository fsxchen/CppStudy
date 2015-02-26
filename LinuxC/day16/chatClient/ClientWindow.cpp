#include "ClientWindow.h"
ClientWindow::ClientWindow(QWidget *p){
    /*QWidget     *center;
    QTextEdit   *edtinfo;
    QLineEdit   *edtmsg;
    QPushButton *btnsend;
    QHBoxLayout *hlay;
    QVBoxLayout *vlay; */
    center = new QWidget(this);
    edtinfo = new QTextEdit(center);
    edtmsg = new QLineEdit(center);
    btnsend = new QPushButton("send", center);
    hlay = new QHBoxLayout();
    vlay = new QVBoxLayout(center);
    vlay->addWidget(edtinfo);
    vlay->addLayout(hlay);

    hlay->addWidget(edtmsg);
    hlay->addWidget(btnsend);

    this->setCentralWidget(center);

    this->show();
}
