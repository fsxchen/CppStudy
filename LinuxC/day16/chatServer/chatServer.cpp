#include <QApplication>
#include <QTextCodec>
#include "ServerWindow.h"
int main(int args, char **argv) {
    QApplication app(args, argv);
    QTextCodec *codec = QTextCodec::codecForName("utf8");

    QTextCodec::setCodecForTr(codec);

    ServerWindow sw;
    return app.exec();
}
