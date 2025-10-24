/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <glwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QSlider *verticalSlider;
    QSlider *verticalSlider_2;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider;
    GLWidget *openGLWidget;
    QTextEdit *textEdit_5;
    QLabel *label_20;
    QPushButton *pushButton_11;
    QGroupBox *groupBox_2;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_8;
    QTextEdit *textEdit_3;
    QLabel *label_16;
    QLineEdit *lineEdit_6;
    QLabel *label_17;
    QLineEdit *lineEdit_7;
    QLabel *label_18;
    QTextEdit *textEdit_4;
    QLabel *label_19;
    QLabel *label_6;
    QSlider *verticalSlider_3;
    QGroupBox *groupBox_3;
    QLabel *label_13;
    QTextEdit *textEdit_2;
    QCheckBox *checkBox_2;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEdit_5;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSlider *horizontalSlider_3;
    QSlider *horizontalSlider_4;
    QSlider *horizontalSlider_5;
    QSlider *horizontalSlider_6;
    QSlider *verticalSlider_4;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_8;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QTextBrowser *textBrowser;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QCheckBox *checkBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(950, 630);
        MainWindow->setMinimumSize(QSize(950, 630));
        MainWindow->setMaximumSize(QSize(950, 630));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(380, 10, 361, 381));
        QFont font;
        font.setBold(false);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        verticalSlider = new QSlider(groupBox);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(10, 60, 21, 281));
        verticalSlider->setCursor(QCursor(Qt::PointingHandCursor));
        verticalSlider->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(165, 29, 45);"));
        verticalSlider->setMinimum(-100);
        verticalSlider->setMaximum(100);
        verticalSlider->setValue(-100);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setTickPosition(QSlider::TicksAbove);
        verticalSlider->setTickInterval(5);
        verticalSlider_2 = new QSlider(groupBox);
        verticalSlider_2->setObjectName(QString::fromUtf8("verticalSlider_2"));
        verticalSlider_2->setGeometry(QRect(330, 60, 21, 281));
        verticalSlider_2->setCursor(QCursor(Qt::PointingHandCursor));
        verticalSlider_2->setAutoFillBackground(false);
        verticalSlider_2->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(26, 95, 180);"));
        verticalSlider_2->setMinimum(-100);
        verticalSlider_2->setMaximum(100);
        verticalSlider_2->setValue(-100);
        verticalSlider_2->setOrientation(Qt::Vertical);
        verticalSlider_2->setTickPosition(QSlider::TicksBelow);
        verticalSlider_2->setTickInterval(5);
        horizontalSlider_2 = new QSlider(groupBox);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setEnabled(true);
        horizontalSlider_2->setGeometry(QRect(40, 350, 281, 21));
        horizontalSlider_2->setCursor(QCursor(Qt::PointingHandCursor));
        horizontalSlider_2->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(26, 95, 180);"));
        horizontalSlider_2->setMinimum(-100);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setValue(-100);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(5);
        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(40, 30, 281, 21));
        horizontalSlider->setCursor(QCursor(Qt::PointingHandCursor));
        horizontalSlider->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(165, 29, 45);"));
        horizontalSlider->setMinimum(-100);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(-100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setTickPosition(QSlider::TicksAbove);
        horizontalSlider->setTickInterval(5);
        openGLWidget = new GLWidget(groupBox);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setEnabled(true);
        openGLWidget->setGeometry(QRect(40, 60, 281, 281));
        textEdit_5 = new QTextEdit(groupBox);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));
        textEdit_5->setGeometry(QRect(90, 40, 261, 321));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(false);
        textEdit_5->setFont(font1);
        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 190, 71, 17));
        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(10, 330, 71, 25));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 301, 331));
        groupBox_2->setFont(font);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 40, 61, 16));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(140, 40, 141, 24));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 80, 101, 16));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 80, 141, 23));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(140, 170, 141, 51));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 180, 41, 16));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 230, 61, 16));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 230, 141, 23));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 260, 61, 16));
        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(140, 260, 141, 23));
        lineEdit_4 = new QLineEdit(groupBox_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(140, 290, 141, 23));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(60, 290, 71, 20));
        textEdit_3 = new QTextEdit(groupBox_2);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setEnabled(true);
        textEdit_3->setGeometry(QRect(140, 30, 141, 31));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        textEdit_3->setFont(font2);
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(30, 40, 91, 20));
        lineEdit_6 = new QLineEdit(groupBox_2);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(140, 70, 141, 23));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(80, 70, 51, 16));
        lineEdit_7 = new QLineEdit(groupBox_2);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(140, 100, 141, 23));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(30, 100, 101, 20));
        textEdit_4 = new QTextEdit(groupBox_2);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(140, 130, 141, 31));
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(50, 140, 71, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(800, 30, 121, 531));
        verticalSlider_3 = new QSlider(centralwidget);
        verticalSlider_3->setObjectName(QString::fromUtf8("verticalSlider_3"));
        verticalSlider_3->setGeometry(QRect(920, 30, 20, 531));
        verticalSlider_3->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(165, 29, 45);"));
        verticalSlider_3->setMinimum(-110);
        verticalSlider_3->setMaximum(80);
        verticalSlider_3->setValue(70);
        verticalSlider_3->setOrientation(Qt::Vertical);
        verticalSlider_3->setTickPosition(QSlider::TicksBothSides);
        verticalSlider_3->setTickInterval(2);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(330, 420, 421, 161));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(260, 30, 18, 23));
        textEdit_2 = new QTextEdit(groupBox_3);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(290, 40, 121, 71));
        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 20, 90, 22));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(290, 20, 61, 23));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(290, 110, 61, 23));
        lineEdit_5 = new QLineEdit(groupBox_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(290, 130, 121, 23));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 50, 251, 111));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalSlider_3 = new QSlider(layoutWidget);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(46, 194, 126);"));
        horizontalSlider_3->setMinimum(-100);
        horizontalSlider_3->setMaximum(100);
        horizontalSlider_3->setValue(-100);
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_3);

        horizontalSlider_4 = new QSlider(layoutWidget);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(46, 194, 126);"));
        horizontalSlider_4->setMinimum(-100);
        horizontalSlider_4->setMaximum(100);
        horizontalSlider_4->setValue(-100);
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_4);

        horizontalSlider_5 = new QSlider(layoutWidget);
        horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
        horizontalSlider_5->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(46, 194, 126);"));
        horizontalSlider_5->setMinimum(1);
        horizontalSlider_5->setMaximum(200);
        horizontalSlider_5->setValue(1);
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_5);

        horizontalSlider_6 = new QSlider(layoutWidget);
        horizontalSlider_6->setObjectName(QString::fromUtf8("horizontalSlider_6"));
        horizontalSlider_6->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(46, 194, 126);"));
        horizontalSlider_6->setMinimum(1);
        horizontalSlider_6->setMaximum(200);
        horizontalSlider_6->setValue(1);
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_6);


        horizontalLayout->addLayout(verticalLayout);

        verticalSlider_4 = new QSlider(layoutWidget);
        verticalSlider_4->setObjectName(QString::fromUtf8("verticalSlider_4"));
        verticalSlider_4->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(46, 194, 126);"));
        verticalSlider_4->setMinimum(-110);
        verticalSlider_4->setMaximum(80);
        verticalSlider_4->setValue(0);
        verticalSlider_4->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider_4);

        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 50, 20, 111));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_2->addWidget(label_10);

        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_2->addWidget(label_11);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_2->addWidget(label_12);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 350, 342, 62));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_8 = new QPushButton(layoutWidget2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_2->addWidget(pushButton_8);

        pushButton_2 = new QPushButton(layoutWidget2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(false);
        pushButton_2->setFont(font3);

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_5 = new QPushButton(layoutWidget2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_3->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(layoutWidget2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font3);

        horizontalLayout_3->addWidget(pushButton_4);

        pushButton_6 = new QPushButton(layoutWidget2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_3->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(layoutWidget2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_3->addWidget(pushButton_7);


        verticalLayout_3->addLayout(horizontalLayout_3);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 420, 311, 161));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_4->addWidget(label_7);

        textBrowser = new QTextBrowser(layoutWidget3);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        horizontalLayout_4->addWidget(textBrowser);

        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(420, 390, 320, 27));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_9 = new QPushButton(layoutWidget4);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        horizontalLayout_5->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(layoutWidget4);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        horizontalLayout_5->addWidget(pushButton_10);

        checkBox = new QCheckBox(layoutWidget4);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_5->addWidget(checkBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 950, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "PHITS DynamicMC", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Dynamics:", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Positions:", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "plot", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "User inputs:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "particle:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Energy (MeV):", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Tally:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "maxcas:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "maxbch:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "step (cm):", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Radioisotope:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "dtime:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Strength (Bq): ", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Projectile:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Shield parameters:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "H", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Shield on", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "material:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "density:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Gen", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Run PHITS", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "View code", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "F5", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Dev info.", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "RI", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Mono E", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Output:", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "text", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "graphical", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Global coordinate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
