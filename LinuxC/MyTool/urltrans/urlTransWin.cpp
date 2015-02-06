#include "urlTransWin.h"
#include <iostream>
using namespace std;

UrlTransWin::UrlTransWin(QWidget *parent) {
    ui = new Ui_urlTrans();
    ui->setupUi(this);
    connect(ui->btnDecode, SIGNAL(clicked()), this, SLOT(decode));

}

UrlTransWin::~UrlTransWin() {
    delete ui;
}

void UrlTransWin::decode() {
    // QString Str = ui->urlTransInput->toPlainText();
    // int l = Str.length();
    cout << "HHHH" << endl;
    // ui->urlTransOutput->setText(Str);

}
