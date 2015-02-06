#include "logindlg.h"

LoginDialog::LoginDialog(QWidget *parent):QDialog(parent){
    lbluser = new QLabel(this);
    lblpass = new QLabel(this);

    edtuser = new QLineEdit(this);
    edtpass = new QLineEdit(this);

    btnlogin = new QPushButton(this);
    btncancel = new QPushButton(this);


    resize(400, 300);
    move((1920-400)/2, (1080-300)/2);

    lbluser->resize(100, 30);
    lbluser->move(50, 40);

    lblpass->resize(100, 30);
    lblpass->move(50, 100);

    edtuser->resize(200, 30);
    edtuser->move(100, 40);

    edtpass->resize(200, 30);
    edtpass->move(100, 100);

    btnlogin->resize(60, 30);
    btnlogin->move(90, 200);

    btncancel->resize(60, 30);
    btncancel->move(250, 200);


    lbluser->setText(QObject::tr("用户:"));
    lblpass->setText(QObject::tr("口令:"));

    btnlogin->setText(QObject::tr("登录"));
    btncancel->setText(QObject::tr("取消"));


}
