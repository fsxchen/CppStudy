#include <QApplication>
#include <QWidget>
#include <QPushButton>
int main(int args, char **argv) {
    QApplication app(args, argv);

    QWidget win;
    QPushButton btn(&win);
    win.resize(400, 300);
    win.move((1024-400)/2, (768-300)/2);

    btn.setVisible(true);
    btn.resize(100, 30);
    btn.move(10, 10);
    btn.setText("确定");
    win.setVisible(true);

    return app.exec();
}
