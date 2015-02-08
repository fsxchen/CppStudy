#include <QApplication>
#include "PaintWidget.h"

main(int args, char **argv) {
    QApplication app(args, argv);

    PaintWidget w;
    w.resize(400, 400);
    w.move((1920-400)/2, (1080-400)/2);
    w.show();

    return app.exec();
}
