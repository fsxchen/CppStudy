/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LOGIN_H
#define LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dlgwin
{
public:
    QLabel *lbluser;
    QLabel *lblpass;
    QPushButton *btnlogin;
    QPushButton *btncancel;
    QLineEdit *edtuser;
    QLineEdit *edtpass;

    void setupUi(QDialog *dlgwin)
    {
        if (dlgwin->objectName().isEmpty())
            dlgwin->setObjectName(QString::fromUtf8("dlgwin"));
        dlgwin->resize(400, 300);
        dlgwin->setSizeGripEnabled(false);
        lbluser = new QLabel(dlgwin);
        lbluser->setObjectName(QString::fromUtf8("lbluser"));
        lbluser->setGeometry(QRect(60, 57, 66, 17));
        QFont font;
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        lbluser->setFont(font);
        lblpass = new QLabel(dlgwin);
        lblpass->setObjectName(QString::fromUtf8("lblpass"));
        lblpass->setGeometry(QRect(60, 113, 66, 17));
        QFont font1;
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        font1.setKerning(false);
        lblpass->setFont(font1);
        btnlogin = new QPushButton(dlgwin);
        btnlogin->setObjectName(QString::fromUtf8("btnlogin"));
        btnlogin->setGeometry(QRect(70, 190, 98, 27));
        btncancel = new QPushButton(dlgwin);
        btncancel->setObjectName(QString::fromUtf8("btncancel"));
        btncancel->setGeometry(QRect(220, 190, 98, 27));
        edtuser = new QLineEdit(dlgwin);
        edtuser->setObjectName(QString::fromUtf8("edtuser"));
        edtuser->setGeometry(QRect(120, 50, 161, 27));
        edtpass = new QLineEdit(dlgwin);
        edtpass->setObjectName(QString::fromUtf8("edtpass"));
        edtpass->setGeometry(QRect(120, 110, 161, 27));

        retranslateUi(dlgwin);

        QMetaObject::connectSlotsByName(dlgwin);
    } // setupUi

    void retranslateUi(QDialog *dlgwin)
    {
        dlgwin->setWindowTitle(QApplication::translate("dlgwin", "Dialog", 0, QApplication::UnicodeUTF8));
        lbluser->setText(QApplication::translate("dlgwin", "\347\224\250\346\210\267:", 0, QApplication::UnicodeUTF8));
        lblpass->setText(QApplication::translate("dlgwin", "\345\217\243\344\273\244:", 0, QApplication::UnicodeUTF8));
        btnlogin->setText(QApplication::translate("dlgwin", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        btncancel->setText(QApplication::translate("dlgwin", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgwin: public Ui_dlgwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LOGIN_H
