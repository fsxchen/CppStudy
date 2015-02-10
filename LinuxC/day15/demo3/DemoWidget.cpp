#include "DemoWidget.h"

DemoWidget::DemoWidget(QWidget *parent):QWidget(parent) {
    edt = new DemoEdit(this);
    edt-> resize(200, 30);
    edt->move(10, 10);
}
