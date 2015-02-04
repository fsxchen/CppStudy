#include <QDialog>
#include <QApplication>

main(int args, char **argv) {
    QApplication app(args, argv);
    //////////////////////////////
    QDialog dlg;
    dlg.setVisible(true);
    //////////////////////////////
    return app.exec();      //让主线程等待所有子线程的结束
}
