#ifndef SHAKE_H
#define SHAKE_H
#include <QDialog>
#include <QLineEdit>
#include "shthread.h"
class ShakeForm : public QDialog {
Q_OBJECT
private:
    QLineEdit *txt;
    ShakeThread *th;
public:
    ShakeForm(QWidget *parent=NULL);
    ~ShakeForm();
};

#endif
