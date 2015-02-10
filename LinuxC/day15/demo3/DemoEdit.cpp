#include "DemoEdit.h"
#include <cstdio>
using namespace std;
DemoEdit::DemoEdit(QWidget *p):QLineEdit(p) {

}
void DemoEdit::keyPressEvent(QKeyEvent *e) {
    // printf("%u:%c:%s\n", e->key(), e->key(), e->text().data());
    int key = e->key();
    if(key >= 65 && key <= 90 || key == Qt::Key_Backspace) {
        QLineEdit::keyPressEvent(e);
    } else{
        this->setText(this->text()+"*");
    }
}
