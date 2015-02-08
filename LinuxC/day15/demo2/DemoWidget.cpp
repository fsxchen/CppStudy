#include "DemoWidget.h"

DemoWidget::DemoWidget(QWidget *parent) :QWidget(parent) {
    btn = new DemoPushButton(this);
    btn->resize(200, 100);
    btn->move(100, 100);
    btn->setText("OK");
}
