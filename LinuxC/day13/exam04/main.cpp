#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QTextCodec>
#include <QLineEdit>
#include <QCheckBox>
#include <QRadioButton>

int main(int args, char **argv) {
    QApplication app(args, argv);
    QTextCodec *codec = QTextCodec::codecForName("utf-8");  //产生一个编码对象

    QTextCodec::setCodecForTr(codec);       //在当前使用这个编码对象

    QDialog dlg;
    dlg.resize(400, 300);
    dlg.move((1024 - 400)/2, (768 - 300)/2);

    QPushButton btn(&dlg);
    btn.resize(100, 30);
    btn.move(100, 100);
    btn.setText(QObject::tr("确定"));     //使用编码对象编码


    QLineEdit edt(&dlg);
    edt.resize(200, 20);
    edt.move(100, 200);

    QCheckBox box(&dlg);
    box.move(100, 250);

    QRadioButton rbtn(&dlg);
    rbtn.move(50, 200);



    dlg.setVisible(true);
    return app.exec();
}
