#include "urlTransWin.h"
#include <iostream>
using namespace std;

UrlTransWin::UrlTransWin(QWidget *parent) {
    ui = new Ui_urlTrans();
    ui->setupUi(this);
    connect(ui->btnDecode, SIGNAL(clicked()), this, SLOT(decode()));

}

UrlTransWin::~UrlTransWin() {
    delete ui;
}

void UrlTransWin::decode() {
    QString str = ui->urlTransInput->toPlainText();
    QString strLower = str.toLower();
    ui->urlTransOutput->setText(strLower);

}
