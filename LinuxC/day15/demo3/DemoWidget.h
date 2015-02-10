#ifndef DEMO3_WIDGET_H
#define DEMO3_WIDGET_H
#include <QWidget>
#include "DemoEdit.h"
class DemoWidget : public QWidget {
private:
    DemoEdit *edt;
public:
    DemoWidget(QWidget *p=NULL);
};
#endif
