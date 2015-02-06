#ifndef DLG_JFQ_H
#define DLG_JFQ_H
#include "frmjfq.h"

class DlgJFQ : public QDialog {
Q_OBJECT
private:
    Ui_DlgJFQ *ui;
public:
    DlgJFQ(QWidget *parent=NULL);
    ~DlgJFQ();
public slots:
    void add();
};

#endif
