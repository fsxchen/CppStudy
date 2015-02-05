#include "shake.h"
ShakeForm::ShakeForm(QWidget *parent) {
    txt = new QLineEdit(this);
    resize(400, 300);

    txt->resize(100, 30);
    txt->move(10, 10);

    th = new ShakeThread();
    connect(th, SIGNAL(setNumber(QString)), txt, SLOT(setText(QString)));
    th->start();
}
ShakeForm::~ShakeForm() {
    delete txt;
}
