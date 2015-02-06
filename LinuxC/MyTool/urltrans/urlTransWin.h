#ifndef URL_TRANS_WIN_H
#define URL_TRANS_WIN_H
#include <QDialog>
#include "frmUrlTrans.h"
class UrlTransWin : public QDialog {
Q_OBJECT
private:
    Ui_urlTrans *ui;
public:
    UrlTransWin(QWidget *parent=NULL);
    ~UrlTransWin();

public slots:
    void decode();
};

#endif
