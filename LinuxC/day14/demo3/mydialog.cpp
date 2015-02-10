#include "mydialog.h"
#include <iostream>
#include <QMessageBox>
using namespace std;
MyDialog::MyDialog(QWidget *parent) {
    resize(400, 300);
    btn = new QPushButton(this);
    btn->resize(100, 30);
    btn->move(150, 150);
    btn->setText("OK");

    connect(btn, SIGNAL(clicked()), this, SLOT(showBox()));
}

MyDialog::~MyDialog() {
    delete btn;
}
void MyDialog::showBox() {
    QMessageBox::information(this, "Informathin", "This is maomao cong!", 0);
}
