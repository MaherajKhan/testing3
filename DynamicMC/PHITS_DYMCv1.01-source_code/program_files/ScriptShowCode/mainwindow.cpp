#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <stdio.h>
#include <time.h>       /* time */
#include <ctype.h>
#include <ctime>
#include <stdio.h>
#include <QMessageBox>
#include <QPixmap>
#include <sstream>
#include "QFile"
#include "QDir"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QString script;



    const QString outj("script.inp");
           QFile outff(outj);
       if(outff.open(QIODevice::ReadOnly)) {
       QTextStream inp(&outff);
       inp >> script;
       outff.close();
       }


       QString scriptloc = script;

//QString script;

       const QString outj1(scriptloc);

              QFile outff1(outj1);
          if(outff1.open(QIODevice::ReadOnly)) {
          QTextStream inp1(&outff1);

         // while (!inp1.atEnd()) {
              //  inp1 >> script;
                    ui->plainTextEdit->insertPlainText(outff1.readAll());
        //  }



          outff1.close();
          }




}

MainWindow::~MainWindow()
{
    delete ui;
}

