#ifndef DLG_YAO_H
#define DLG_YAO_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "thyao.h"

class DlgYao: public QWidget {
Q_OBJECT
private:
    QLabel *lblnum;
    QPushButton *btnyao;
    ThYao *th;
    bool isstop;
public:
    DlgYao(QWidget *p=NULL);
public slots:
    void yao();
public: signals:
    void control(bool);
};
#endif
