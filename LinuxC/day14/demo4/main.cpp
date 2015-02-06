#include <QApplication>
#include "dlgjfq.h"

int main(int args, char **argv) {
    QApplication app(args, argv);
    DlgJFQ dlg;
    // dlg.setVisible(true);
    dlg.show();
    return app.exec();
}
