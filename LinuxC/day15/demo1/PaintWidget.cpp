#include "PaintWidget.h"
#include <QPainter>

void PaintWidget::paintEvent(QPaintEvent *e) {
    //进行绘制工作
    QPoint p[3];
    p[0].setX(10);
    p[0].setY(10);

    p[1].setX(300);
    p[1].setY(10);

    p[2].setX(145);
    p[2].setY(200);
    //1.产生绘制对象QPainter
    QPainter g(this);   //this参数实际上是指定绘制目标

    //2.设置绘制对象的属性
    //3.进行绘制:几何图形,图像与字符串
    g.drawLine(10,10, 400, 400);

    g.drawChord(10, 10, 400, 400, 10*16, 120 *16);

    g.drawChord(100, 10, 300, 300, 150*16, 270 *16);

    g.drawConvexPolygon(p, 3);

    g.drawEllipse(0, 0, this->width(), this->height());
}
