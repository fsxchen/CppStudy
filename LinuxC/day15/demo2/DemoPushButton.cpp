#include "DemoPushButton.h"
#include <QPainter>
#include <QColor>
#include <QBrush>
#include <QPen>

DemoPushButton::DemoPushButton(QWidget *parent) : QPushButton(parent), israised(true) {

}

void DemoPushButton::enterEvent(QEvent *e) {
    israised = false;
    repaint();
}

void DemoPushButton::leaveEvent(QEvent *e) {
    israised = true;
    repaint();
}

void DemoPushButton::paintEvent(QPaintEvent *e) {
    int w = width();
    int h = height();
    QColor clrw(255, 255, 255);
    QColor clrb(0, 0, 0);
    QBrush brw(clrw);
    QBrush brb(clrb);

    QPen penw(brw, 2);
    QPen penb(brb, 2);

    QPoint pttop(w/2, 0);
    QPoint ptbottom(w/2, h);
    QPoint ptleft(0, (h+2)/2);
    QPoint ptrigth(w, (h+2)/2);

    QPainter g(this);

    if(israised) {
        g.setPen(penw);
    } else {
        g.setPen(penb);

    }

    g.drawLine(pttop, ptleft);
    g.drawLine(pttop, ptrigth);

    if(israised) {
        g.setPen(penb);
    } else {
        g.setPen(penw);

    }

    g.drawLine(ptbottom, ptleft);
    g.drawLine(ptbottom, ptrigth);
}
