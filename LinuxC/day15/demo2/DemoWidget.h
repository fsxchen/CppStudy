#ifndef DEMO2_WIDGET_H
#define DEMO2_WIDGET_H
#include <QWidget>
#include "DemoPushButton.h"

class DemoWidget: public QWidget {
private:
    DemoPushButton *btn;
    DemoPushButton *btn2;
public:
    DemoWidget(QWidget *parent=NULL);
};
#endif
