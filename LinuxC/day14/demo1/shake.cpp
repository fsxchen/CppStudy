#include "shake.h"
ShakeForm::ShakeForm(QWidget *parent) {
    txt = new QLineEdit(this);
    resize(400, 300);

    txt->resize(100, 30);
    txt->move(10, 10);

    th = new ShakeThread(txt);
    th->start();
}
ShakeForm::~ShakeForm() {
    delete txt;
}
