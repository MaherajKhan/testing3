/********************************************************************************
** Form generated from reading UI file 'tallyplot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TALLYPLOT_H
#define UI_TALLYPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_tallyplot
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCustomPlot *plot;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *tallyplot)
    {
        if (tallyplot->objectName().isEmpty())
            tallyplot->setObjectName(QString::fromUtf8("tallyplot"));
        tallyplot->resize(600, 600);
        tallyplot->setMinimumSize(QSize(600, 600));
        tallyplot->setMaximumSize(QSize(600, 600));
        centralwidget = new QWidget(tallyplot);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 10, 502, 535));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        plot = new QCustomPlot(layoutWidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setMinimumSize(QSize(500, 500));
        plot->setMaximumSize(QSize(500, 500));

        verticalLayout->addWidget(plot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QFont font;
        font.setPointSize(9);
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        tallyplot->setCentralWidget(centralwidget);
        menubar = new QMenuBar(tallyplot);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 22));
        tallyplot->setMenuBar(menubar);
        statusbar = new QStatusBar(tallyplot);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        tallyplot->setStatusBar(statusbar);

        retranslateUi(tallyplot);

        QMetaObject::connectSlotsByName(tallyplot);
    } // setupUi

    void retranslateUi(QMainWindow *tallyplot)
    {
        tallyplot->setWindowTitle(QCoreApplication::translate("tallyplot", "TallyPlot", nullptr));
        pushButton->setText(QCoreApplication::translate("tallyplot", "Plot Tally", nullptr));
        label->setText(QCoreApplication::translate("tallyplot", "tally name:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("tallyplot", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tallyplot: public Ui_tallyplot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TALLYPLOT_H
