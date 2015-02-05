#include <QApplication>
#include "shake.h"


int main(int args, char** argv) {
    QApplication app(args, argv);

    ShakeForm dlg;

    dlg.setVisible(true);

    return app.exec();
}
