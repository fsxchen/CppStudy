#include <QApplication>
#include <QWidget>
#include <QIcon>

int main(int args, char**argv) {
    QApplication app(args, argv);
    QWidget w;
    // w.resize(QSize(400, 300));
    // w.move(QPoint((1920-400)/2, (1080-300)/2));
    w.setGeometry(QRect((1920-400)/2, (1080-300)/2 , 400, 400));

    //光标属性
    QCursor cur(Qt::CrossCursor);
    w.setCursor(cur);

    QIcon ico("aa.png");
    w.setWindowIcon(ico);

    w.setToolTip("<font size='45' color=red>HELLO</font>");     //支持html

    w.setVisible(true);

    return app.exec();
}
