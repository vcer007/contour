/********************************************************************************
** Form generated from reading UI file 'contourframe.ui'
**
** Created: Sat Mar 5 23:35:56 2011
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTOURFRAME_H
#define UI_CONTOURFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QScrollBar>
#include <QtGui/QWidget>
#include "./dialog/colorruler.h"
#include "contourview.h"
#include "coordinate.h"

QT_BEGIN_NAMESPACE

class Ui_CFrame
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    Coordinate *ycoordinate;
    ContourView *view;
    QScrollBar *verticalScrollBar;
    ColorRuler *colorFrame;
    Coordinate *xcoordinate;
    QScrollBar *horizontalScrollBar;
    QFrame *labelFrame;
    QLabel *iLabel;
    QLabel *jLabel;
    QLabel *zLabel;

    void setupUi(QWidget *CFrame)
    {
        if (CFrame->objectName().isEmpty())
            CFrame->setObjectName(QString::fromUtf8("CFrame"));
        CFrame->resize(731, 518);
        horizontalLayout = new QHBoxLayout(CFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ycoordinate = new Coordinate(CFrame);
        ycoordinate->setObjectName(QString::fromUtf8("ycoordinate"));
        ycoordinate->setMinimumSize(QSize(50, 0));
        ycoordinate->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(ycoordinate, 0, 0, 1, 1);

        view = new ContourView(CFrame);
        view->setObjectName(QString::fromUtf8("view"));

        gridLayout->addWidget(view, 0, 1, 1, 1);

        verticalScrollBar = new QScrollBar(CFrame);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setMaximumSize(QSize(12, 16777215));
        verticalScrollBar->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalScrollBar, 0, 2, 2, 1);

        colorFrame = new ColorRuler(CFrame);
        colorFrame->setObjectName(QString::fromUtf8("colorFrame"));
        colorFrame->setMinimumSize(QSize(80, 0));
        colorFrame->setFrameShape(QFrame::StyledPanel);
        colorFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(colorFrame, 0, 3, 1, 1);

        xcoordinate = new Coordinate(CFrame);
        xcoordinate->setObjectName(QString::fromUtf8("xcoordinate"));
        xcoordinate->setMinimumSize(QSize(0, 50));
        xcoordinate->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(xcoordinate, 1, 1, 1, 1);

        horizontalScrollBar = new QScrollBar(CFrame);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setMaximumSize(QSize(16777215, 12));
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalScrollBar, 2, 0, 1, 2);

        labelFrame = new QFrame(CFrame);
        labelFrame->setObjectName(QString::fromUtf8("labelFrame"));
        labelFrame->setFrameShape(QFrame::StyledPanel);
        labelFrame->setFrameShadow(QFrame::Raised);
        iLabel = new QLabel(labelFrame);
        iLabel->setObjectName(QString::fromUtf8("iLabel"));
        iLabel->setGeometry(QRect(10, 0, 59, 19));
        jLabel = new QLabel(labelFrame);
        jLabel->setObjectName(QString::fromUtf8("jLabel"));
        jLabel->setGeometry(QRect(10, 20, 59, 19));
        zLabel = new QLabel(labelFrame);
        zLabel->setObjectName(QString::fromUtf8("zLabel"));
        zLabel->setGeometry(QRect(10, 40, 59, 19));

        gridLayout->addWidget(labelFrame, 1, 3, 2, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(CFrame);

        QMetaObject::connectSlotsByName(CFrame);
    } // setupUi

    void retranslateUi(QWidget *CFrame)
    {
        CFrame->setWindowTitle(QApplication::translate("CFrame", "Form", 0, QApplication::UnicodeUTF8));
        iLabel->setText(QApplication::translate("CFrame", "TextLabel", 0, QApplication::UnicodeUTF8));
        jLabel->setText(QApplication::translate("CFrame", "TextLabel", 0, QApplication::UnicodeUTF8));
        zLabel->setText(QApplication::translate("CFrame", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CFrame: public Ui_CFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTOURFRAME_H
