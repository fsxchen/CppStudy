#include <QApplication>
#include <urlTransWin.h>
int main(int args, char**argv) {
    QApplication app(args, argv);

    UrlTransWin utw;
    utw.show();

    return app.exec();
}
