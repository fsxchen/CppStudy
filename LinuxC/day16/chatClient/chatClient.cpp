#include "ClientWindow.h"
#include <QApplication>
int main(int args, char **argv) {
    QApplication app(args, argv);

    ClientWindow cw;
    return app.exec();
}
