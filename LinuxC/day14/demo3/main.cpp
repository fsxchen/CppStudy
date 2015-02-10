#include <QApplication>
#include "mydialog.h"
int main(int args, char **argv) {
    QApplication app(args, argv);

    MyDialog dlg;
    dlg.setVisible(true);

    return app.exec();
}
