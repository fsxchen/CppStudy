#ifndef DEMO2_PUSHBUTTON_H
#define DEMO2_PUSHBUTTON_H
#include <QPushButton>
#include <QPaintEvent>
#include <QEvent>

#include "DemoPushButton.h"

class DemoPushButton:public QPushButton {
private:
    bool israised;
public:
    DemoPushButton(QWidget *parent=NULL);
protected:
    virtual void paintEvent(QPaintEvent *e);
    virtual void enterEvent(QEvent *e);
    virtual void leaveEvent(QEvent *e);
};
#endif
