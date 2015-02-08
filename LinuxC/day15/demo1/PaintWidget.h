#ifndef PAIN_WIDGET_H
#define PAIN_WIDGET_H

#include <QWidget>
#include <QPaintEvent>
class PaintWidget: public QWidget {
protected:
    virtual void paintEvent(QPaintEvent *e);
};

#endif
