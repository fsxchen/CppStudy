#include "PaintWidget.h"
#include <QPainter>
#include <QPixmap>
#include <QBitmap>
#include <QPen>

PaintWidget::PaintWidget():mouth(30), isopen(false) {
    timer.setInterval(100);
    timer.start();
    connect(&timer, SIGNAL(timeout()), this, SLOT(openMouth()));
}

void PaintWidget::openMouth() {
    if(isopen) {
        mouth += 1;
        if(mouth >= 30) {
            mouth = 30;
            isopen = !isopen;
        }
    } else {
        mouth -= 1;
        if(mouth <= 0) {
            mouth = 0;
            isopen = !isopen;
        }
    }
    repaint();  //强制调用paintEvent事件函数
}
void PaintWidget::paintEvent(QPaintEvent *e) {
    QPainter g(this);   //this参数实际上是指定绘制目标
    g.drawPie(100, 100, 100, 100, mouth * 16, (360 - 2*mouth) * 16);
    //进行绘制工作
    // QPoint p[3];
    // p[0].setX(10);
    // p[0].setY(10);
    //
    // p[1].setX(300);
    // p[1].setY(10);
    //
    // p[2].setX(145);
    // p[2].setY(200);
    //
    // QImage img("qq.png");
    // QPixmap map("bigmouthfish/00.PNG");
    // QBitmap bit = map.createMaskFromColor(QColor(255, 255, 255,255));
    //
    // // QPen pen(QColor(255, 0, 0));
    // QBrush br(QColor(0, 255, 255));
    // QPen pen(br, 3);
    // //1.产生绘制对象QPainter

    //
    // //2.设置绘制对象的属性
    // //3.进行绘制:几何图形,图像与字符串
    // g.drawLine(10,10, 400, 400);
    // g.drawChord(10, 10, 400, 400, 10*16, 120 *16);
    //
    // g.setPen(pen);
    //
    // // g.setClipRect(0, 0, 100, 100);   //屏蔽这个区域之外的
    //
    // g.drawChord(100, 10, 300, 300, 150*16, 270 *16);
    //
    // g.drawConvexPolygon(p, 3);
    //
    // g.drawPie(20, 10, 200, 200, 10*16, 120 *16);
    //
    // g.drawEllipse(0, 0, this->width(), this->height());
    //
    // g.setFont(QFont("隶书", 45, 100));
    // g.rotate(30);
    // g.drawText(100, 100, "this is maomaochong!");
    // // g.drawImage(10, 10, img, 0, 0, 200, 200);
    // map.setMask(bit);
    // g.drawPixmap(10, 10, 36, 36, map);


}
