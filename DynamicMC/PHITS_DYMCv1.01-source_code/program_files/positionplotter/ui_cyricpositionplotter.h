/********************************************************************************
** Form generated from reading UI file 'cyricpositionplotter.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CYRICPOSITIONPLOTTER_H
#define UI_CYRICPOSITIONPLOTTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_cyricpositionplotter
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCustomPlot *plot;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *cyricpositionplotter)
    {
        if (cyricpositionplotter->objectName().isEmpty())
            cyricpositionplotter->setObjectName(QString::fromUtf8("cyricpositionplotter"));
        cyricpositionplotter->resize(500, 500);
        cyricpositionplotter->setMinimumSize(QSize(500, 500));
        cyricpositionplotter->setMaximumSize(QSize(500, 500));
        centralwidget = new QWidget(cyricpositionplotter);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 10, 402, 435));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        plot = new QCustomPlot(widget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setMinimumSize(QSize(400, 400));
        plot->setMaximumSize(QSize(400, 400));

        verticalLayout->addWidget(plot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        horizontalLayout->addWidget(lcdNumber);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);

        cyricpositionplotter->setCentralWidget(centralwidget);
        menubar = new QMenuBar(cyricpositionplotter);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 22));
        cyricpositionplotter->setMenuBar(menubar);
        statusbar = new QStatusBar(cyricpositionplotter);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        cyricpositionplotter->setStatusBar(statusbar);

        retranslateUi(cyricpositionplotter);

        QMetaObject::connectSlotsByName(cyricpositionplotter);
    } // setupUi

    void retranslateUi(QMainWindow *cyricpositionplotter)
    {
        cyricpositionplotter->setWindowTitle(QCoreApplication::translate("cyricpositionplotter", "CyricPositionPlotter", nullptr));
        pushButton->setText(QCoreApplication::translate("cyricpositionplotter", "Cycle Positions", nullptr));
        label->setText(QCoreApplication::translate("cyricpositionplotter", "plotted position:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("cyricpositionplotter", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cyricpositionplotter: public Ui_cyricpositionplotter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CYRICPOSITIONPLOTTER_H
