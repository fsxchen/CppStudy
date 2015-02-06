/********************************************************************************
** Form generated from reading UI file 'frmUrlTrans.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FRMURLTRANS_H
#define FRMURLTRANS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_urlTrans
{
public:
    QFrame *frame;
    QPlainTextEdit *urlTransInput;
    QTextBrowser *urlTransOutput;
    QPushButton *btnDecode;

    void setupUi(QDialog *urlTrans)
    {
        if (urlTrans->objectName().isEmpty())
            urlTrans->setObjectName(QString::fromUtf8("urlTrans"));
        urlTrans->resize(600, 537);
        urlTrans->setMinimumSize(QSize(600, 537));
        frame = new QFrame(urlTrans);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(3, 6, 591, 524));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        urlTransInput = new QPlainTextEdit(frame);
        urlTransInput->setObjectName(QString::fromUtf8("urlTransInput"));
        urlTransInput->setGeometry(QRect(10, 10, 571, 221));
        urlTransOutput = new QTextBrowser(frame);
        urlTransOutput->setObjectName(QString::fromUtf8("urlTransOutput"));
        urlTransOutput->setGeometry(QRect(10, 240, 571, 221));
        btnDecode = new QPushButton(frame);
        btnDecode->setObjectName(QString::fromUtf8("btnDecode"));
        btnDecode->setGeometry(QRect(230, 480, 98, 27));

        retranslateUi(urlTrans);

        QMetaObject::connectSlotsByName(urlTrans);
    } // setupUi

    void retranslateUi(QDialog *urlTrans)
    {
        urlTrans->setWindowTitle(QApplication::translate("urlTrans", "url\350\275\254\346\215\242\345\267\245\345\205\267", 0, QApplication::UnicodeUTF8));
        btnDecode->setText(QApplication::translate("urlTrans", "URL\350\247\243\347\240\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class urlTrans: public Ui_urlTrans {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FRMURLTRANS_H
