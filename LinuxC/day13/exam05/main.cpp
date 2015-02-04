#include <QApplication>
#include <QTextCodec>
#include "logindlg.h"
int main(int args, char **argv) {
    QApplication app(args, argv);
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForTr(codec);

    LoginDialog dlg;
    dlg.resize(400, 300);
    dlg.setVisible(true);

    return app.exec();
}
