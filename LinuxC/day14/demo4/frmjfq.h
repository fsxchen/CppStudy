/********************************************************************************
** Form generated from reading UI file 'frmjfq.ui'
**
** Created: Fri Feb 6 15:53:38 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FRMJFQ_H
#define FRMJFQ_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DlgJFQ
{
public:
    QFrame *frame;
    QLineEdit *txtAdded;
    QLineEdit *txtAdd;
    QLabel *label;
    QPushButton *btnAdd;
    QLabel *lblResult;

    void setupUi(QDialog *DlgJFQ)
    {
        if (DlgJFQ->objectName().isEmpty())
            DlgJFQ->setObjectName(QString::fromUtf8("DlgJFQ"));
        DlgJFQ->resize(450, 100);
        DlgJFQ->setMinimumSize(QSize(450, 100));
        DlgJFQ->setMaximumSize(QSize(450, 100));
        frame = new QFrame(DlgJFQ);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(5, 10, 441, 81));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        txtAdded = new QLineEdit(frame);
        txtAdded->setObjectName(QString::fromUtf8("txtAdded"));
        txtAdded->setGeometry(QRect(18, 22, 100, 30));
        txtAdd = new QLineEdit(frame);
        txtAdd->setObjectName(QString::fromUtf8("txtAdd"));
        txtAdd->setGeometry(QRect(151, 22, 101, 32));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(128, 27, 21, 23));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        btnAdd = new QPushButton(frame);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(265, 22, 34, 30));
        lblResult = new QLabel(frame);
        lblResult->setObjectName(QString::fromUtf8("lblResult"));
        lblResult->setGeometry(QRect(310, 22, 103, 29));
        lblResult->setFrameShape(QFrame::Box);
        lblResult->setFrameShadow(QFrame::Raised);

        retranslateUi(DlgJFQ);

        QMetaObject::connectSlotsByName(DlgJFQ);
    } // setupUi

    void retranslateUi(QDialog *DlgJFQ)
    {
        DlgJFQ->setWindowTitle(QApplication::translate("DlgJFQ", "\345\212\240\346\263\225\345\231\250", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DlgJFQ", "+", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("DlgJFQ", "=", 0, QApplication::UnicodeUTF8));
        lblResult->setText(QApplication::translate("DlgJFQ", "result", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgJFQ: public Ui_DlgJFQ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FRMJFQ_H
