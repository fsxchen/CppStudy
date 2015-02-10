#include <QApplication>
#include "MainWin.h"
int main(int args, char**argv) {
    QApplication app(args, argv);

    MainWindow w; 
    w.show(); 
    return app.exec();
}