#include "dlgyao.h"
DlgYao::DlgYao(QWidget *p)
    : QWidget(p) {
        lblnum = new QLabel(this);
        btnyao = new QPushButton("start", this);

        resize(400, 300);
        move((1920-400)/2, (1080-300)/2);
        lblnum->move(150, 150);
        lblnum->resize(100, 30);
        lblnum->setFrameShape(QFrame::Box);

        btnyao->move(150, 210);
        btnyao->resize(80, 30);

        th = new ThYao();

        connect(btnyao, SIGNAL(clicket()), this, SLOT(yao()));
        connect(th, SIGNAL(number(const QString&)), lblnum, SLOT(setText(const QString&)));
        connect(this, SIGNAL(control(bool)), th, SLOT(control(bool)));
        th->start();
}
void DlgYao::yao() {
    isstop=!isstop;
    if(!isstop){
        btnyao->setText("stop");
    }else{
        btnyao->setText("again");
    }
    emit control(isstop);
}
