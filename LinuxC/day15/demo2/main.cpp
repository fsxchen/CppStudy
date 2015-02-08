#include <QApplication>
#include "DemoWidget.h"

int main(int args, char **argv) {
    QApplication app(args, argv);

    DemoWidget w;
    w.resize(400, 400);
    w.show();

    return app.exec();
}
