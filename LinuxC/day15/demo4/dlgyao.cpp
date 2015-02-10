#include "dlgyao.h"
#include <cstdio>

DlgYao::DlgYao(QWidget *p)
    : QWidget(p), isstop(false) {
    lblnum = new QLabel(this);
    btnyao = new QPushButton("start", this);

    resize(400, 300);
    move((1920-400)/2, (1080-300)/2);
    lblnum->move(150, 150);
    lblnum->resize(100, 30);
    lblnum->setFrameShape(QFrame::Box);

    btnyao->move(150, 210);
    btnyao->resize(80, 30);



    connect(btnyao, SIGNAL(clicked()), this, SLOT(yao()));
    th = new ThYao();
    connect(th, SIGNAL(number(const QString&)), lblnum, SLOT(setText(const QString&)));
    connect(this, SIGNAL(control(bool)), th, SLOT(control(bool)));
    th->start();

    setVisible(true);

}
void DlgYao::yao() {
    isstop = !isstop;
    printf("yaoyao\n");
    if(!isstop){
        btnyao->setText("stop");
    }else{
        btnyao->setText("again");
    }
    emit control(isstop);
}
