#ifndef SERVER_WINDOW_H
#define SERVER_WINDOW_H
#include <QMainWindow>
#include <QTextEdit>
class ServerWindow:public QMainWindow {
private:
    QTextEdit *info;
public:
    ServerWindow(QWidget *p=NULL);
};

#endif
