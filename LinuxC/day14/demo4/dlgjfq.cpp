#include "dlgjfq.h"
DlgJFQ::DlgJFQ(QWidget *parent) {
    ui = new Ui_DlgJFQ;
    ui->setupUi(this);
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(add()));
}
DlgJFQ::~DlgJFQ() {
    delete ui;
}

void DlgJFQ::add() {
    //取字符创
    QString strAdded = ui->txtAdded->text();
    QString strAdd = ui->txtAdd-> text();
    //转换整数
    int ia = strAdded.toInt();
    int ib = strAdd.toInt();
    //计算和
    int sum = ia + ib;
    //把和转换为文本，显示到标签框
    ui->lblResult->setText(QString::number(sum));
}
