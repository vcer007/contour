/********************************************************************************
** Form generated from reading UI file 'helpdialog.ui'
**
** Created: Sat Mar 5 23:35:56 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HelpDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *htmlButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *HelpDialog)
    {
        if (HelpDialog->objectName().isEmpty())
            HelpDialog->setObjectName(QString::fromUtf8("HelpDialog"));
        HelpDialog->resize(315, 224);
        HelpDialog->setMinimumSize(QSize(315, 224));
        HelpDialog->setMaximumSize(QSize(315, 224));
        label = new QLabel(HelpDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 231, 51));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(HelpDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 271, 31));
        label_3 = new QLabel(HelpDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 90, 111, 19));
        label_4 = new QLabel(HelpDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 120, 211, 19));
        htmlButton = new QPushButton(HelpDialog);
        htmlButton->setObjectName(QString::fromUtf8("htmlButton"));
        htmlButton->setGeometry(QRect(90, 150, 131, 21));
        QFont font1;
        font1.setBold(false);
        font1.setUnderline(true);
        font1.setWeight(50);
        htmlButton->setFont(font1);
        htmlButton->setAutoDefault(true);
        pushButton_2 = new QPushButton(HelpDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 190, 84, 29));

        retranslateUi(HelpDialog);
        QObject::connect(pushButton_2, SIGNAL(clicked()), HelpDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(HelpDialog);
    } // setupUi

    void retranslateUi(QDialog *HelpDialog)
    {
        HelpDialog->setWindowTitle(QApplication::translate("HelpDialog", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HelpDialog", "Jian's contour", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("HelpDialog", "jian's contour\346\230\257\344\270\200\344\270\252\347\255\211\345\200\274\347\272\277\345\244\204\347\220\206\347\250\213\345\272\217,\345\256\203\345\217\257\344\273\245\345\257\271", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HelpDialog", "\347\246\273\346\225\243\346\225\260\346\215\256\350\277\233\350\241\214\345\244\204\347\220\206", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("HelpDialog", "\347\211\210\346\235\203 (C)  2009  Jian's contour \344\275\234\350\200\205", 0, QApplication::UnicodeUTF8));
        htmlButton->setText(QApplication::translate("HelpDialog", "Jian's contour\347\275\221\347\253\231", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("HelpDialog", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HelpDialog: public Ui_HelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H
