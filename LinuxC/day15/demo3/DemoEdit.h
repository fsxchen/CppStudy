#ifndef DEMO3_EDIT_H
#define DEMO3_EDIT_H
#include <QLineEdit>
#include <QWidget>
#include <QKeyEvent>
class DemoEdit: public QLineEdit {
public:
    DemoEdit(QWidget *parent=NULL);
protected:
    void keyPressEvent(QKeyEvent *e);
};
#endif
