#include <QApplication>
#include "dlgyao.h"
int main(int args, char **argv) {
    QApplication app(args, argv);

    DlgYao w;

    w.setVisible(true);

    return app.exec();
}
