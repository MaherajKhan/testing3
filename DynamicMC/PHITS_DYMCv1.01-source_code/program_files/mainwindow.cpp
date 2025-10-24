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
#include <QDialog>
#include <sys/stat.h>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

  int systemRet = system("rm runphits.bat");
    //int systemRet = system("rm runphits.bat");
    if(systemRet == -1){
        ui->textBrowser->setTextColor(Qt::red);
        ui->textBrowser->insertPlainText("rm runphits.bat command failed!\n");
        // The system method failed
    }

    int systemRet5 = system("rm sumtally.tmp");
    //int systemRet = system("rm runphits.bat");
    if(systemRet5 == -1){
        ui->textBrowser->setTextColor(Qt::red);
        ui->textBrowser->insertPlainText("rm sumtally.tmp command failed!\n");
        // The system method failed
    }


    ui->setupUi(this);

    //disable graphical input

    ui->textEdit_5->setVisible(false);

    ui->label_20->setVisible(false);



  ui->lineEdit->setVisible(false);

  ui->label_2->setVisible(false);

  ui->comboBox->setVisible(false);

  ui->label->setVisible(false);

  ui->pushButton_11->setVisible(false);

  ui->textEdit_3->setVisible(true);

  ui->label_16->setVisible(true);

  ui->lineEdit_6->setVisible(true);
  ui->lineEdit_7->setVisible(true);

  ui->label_17->setVisible(true);
  ui->label_18->setVisible(true);

  ui->textEdit_4->setVisible(true);

  ui->label_19->setVisible(true);


  ui->textEdit_3->setText("Cs-137");

  ui->lineEdit_6->setText("-10.0");

  ui->lineEdit_7->setText("100.0");

  ui->textEdit_4->setText("photon");

  ui->textEdit->setText("photon");

    ui->textEdit->setText("photon");


        ui->lineEdit_2->setText("1000");

        ui->lineEdit_3->setText("10");

        ui->lineEdit_4->setText("1");


        ui->textEdit_2->setText("82000 -1.0");

        ui->lineEdit_5->setText("11.29");

        const QString qPath2("dymcmode.tmpz");
        QFile qFile2(qPath2);
          if (qFile2.open(QIODevice::WriteOnly)) {
            QTextStream out2(&qFile2);
            out2 << "RI";
            qFile2.close();
          }


          const QString qPath29("coordinatemode.tmp");
          QFile qFile29(qPath29);
          if (qFile29.open(QIODevice::WriteOnly)) {
            QTextStream out29(&qFile29);
            out29 << "g";
            qFile29.close();
          }


         
          struct stat sb;
          int num=1;
          for(int i=0; i <1000; i++)
          {

             //const char* dir = "../working_directory/"+char(i);

             std::string dirs = "../working_directory/run"+to_string(num);

             const char* dir = dirs.c_str();  //new char[dirs.length() + 1];

//             strcpy(dir, dirs.c_str());

          if(stat(dir, &sb) == 0)
          {
            num++;

//            cout << dir << endl;
  //           system("echo hellop");

          }
          else
          {
            //num++;
          //  cout << dir << endl;
            //system("mkdir ");
          }

                    const QString qPath155("working_dir.sh");
        QFile qFile155(qPath155);
        if (qFile155.open(QIODevice::WriteOnly)) {
          QTextStream out155(&qFile155);
          out155 << "mkdir ";
          out155 << dir;
          qFile155.close();
        }


        const QString qPath156("working_dir.tmpz");
        QFile qFile156(qPath156);
        if (qFile156.open(QIODevice::WriteOnly)) {
          QTextStream out156(&qFile156);
          out156 << dir;
          qFile156.close();
        }

          }


         int systemRet2 = system("sh working_dir.sh");
          //int systemRet2 = system("sh working_dir.sh");
          if(systemRet2 == -1){
        ui->textBrowser->setTextColor(Qt::red);
        ui->textBrowser->insertPlainText("sh working_dir.sh command failed!\n");
        // The system method failed
          }





          




   // glwin = new GLWidget(this);

   // connect(glwin,SIGNAL(on_verticalSlider_valueChanged(int)), this, SLOT(on_verticalSlider_valueChanged_rec(int)));

      //  QObject::connect(glwin,SIGNAL(vertical_slider(int)),this,SLOT(on_verticalSlider_valueChanged(int)));


    //GLWidget* glw = new GLWidget(this);
     //  this->setCentralWidget(glw);

   // ui->horizontalSlider->setStyleSheet("QSlider::groove:horizontal {background-color:yellow;}"
   //                                     "Qslider::handle:horizontal {background-color:red;}");


    QPixmap pix("phantom.png");

    ui->label_6->setPixmap(pix);

   //QObject::connect()

  //    int sy = ui->verticalSlider->value();

 //  connect(ui->verticalSlider, &QSlider::valueChanged,this, &GLWidget::value);

}



MainWindow::~MainWindow()
{
    delete ui;
}

//collision(value1x,value2x,value3x,value4x);

void MainWindow::on_verticalSlider_valueChanged(int value)
{

  //  ui->verticalSlider->value();
      //value = 1;

    QString steps = ui->lineEdit_4->text();

    int step = steps.toInt();

    int syc = (value +100) * step;

        QString sycs = QString::number(syc);



    QString sy = QString::number(value);

      const QString qPath1("sy.tmp");
      QFile qFile1(qPath1);
        if (qFile1.open(QIODevice::WriteOnly)) {
          QTextStream out1(&qFile1);
          out1 << sy;
          qFile1.close();
        }


    ui->textBrowser->setTextColor(Qt::red);
    //ui->textBrowser->setText(sycs);
        ui->textBrowser->setText(">> Source Y position: "+sycs+" cm\n");
        ui->textBrowser->setTextColor(Qt::black);

}



void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    //ui->horizontalSlider->value();
      //value = 1;

    QString steps = ui->lineEdit_4->text();

    int step = steps.toInt();

    int sxc = (value+100) * step;

        QString sxcs = QString::number(sxc);

    QString sx = QString::number(value);

      const QString qPath2("sx.tmp");
      QFile qFile2(qPath2);
        if (qFile2.open(QIODevice::WriteOnly)) {
          QTextStream out2(&qFile2);
          out2 << sx;
          qFile2.close();
        }

        ui->textBrowser->setTextColor(Qt::red);
        ui->textBrowser->setText(">> Source X position: "+sxcs+" cm\n");
        ui->textBrowser->setTextColor(Qt::black);

}





void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{

    QString steps = ui->lineEdit_4->text();

    int step = steps.toInt();

    int pxc = (value+100) * step;

        QString pxcs = QString::number(pxc);

    ui->horizontalSlider_2->value();
      //value = 1;

    QString px = QString::number(value);

      const QString qPath3("px.tmp");
      QFile qFile3(qPath3);
        if (qFile3.open(QIODevice::WriteOnly)) {
          QTextStream out3(&qFile3);
          out3 << px;
          qFile3.close();
        }


        ui->textBrowser->setTextColor(Qt::blue);
        ui->textBrowser->setText("## Phantom X position: "+pxcs+" cm\n");
        ui->textBrowser->setTextColor(Qt::black);
}


void MainWindow::on_verticalSlider_2_valueChanged(int value)
{
    ui->verticalSlider_2->value();

    QString steps = ui->lineEdit_4->text();

    int step = steps.toInt();

    int pyc = (value+100) * step;

        QString pycs = QString::number(pyc);
      //value = 1;

    QString py = QString::number(value);

      const QString qPath4("py.tmp");
      QFile qFile4(qPath4);
        if (qFile4.open(QIODevice::WriteOnly)) {
          QTextStream out4(&qFile4);
          out4 << py;
          qFile4.close();
        }


        ui->textBrowser->setTextColor(Qt::blue);
        ui->textBrowser->setText("## Phantom Y position: "+pycs+" cm\n");
        ui->textBrowser->setTextColor(Qt::black);

}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{

    ui->horizontalSlider_3->value();

    QString steps = ui->lineEdit_4->text();

    int step = steps.toInt();

    int pyc = (value+100) * step;

        QString pycs = QString::number(pyc);
      //value = 1;

    QString py = QString::number(value);

      const QString qPath4("shx.tmp");
      QFile qFile4(qPath4);
        if (qFile4.open(QIODevice::WriteOnly)) {
          QTextStream out4(&qFile4);
          out4 << py;
          qFile4.close();
        }


        ui->textBrowser->setTextColor(Qt::green);
        ui->textBrowser->setText("$$ Shield X position: "+pycs+" cm\n");
        ui->textBrowser->setTextColor(Qt::black);

}


void MainWindow::on_horizontalSlider_4_valueChanged(int value)
{

    ui->horizontalSlider_4->value();

    QString steps = ui->lineEdit_4->text();

    int step = steps.toInt();

    int pyc = (value+100) * step;

        QString pycs = QString::number(pyc);
      //value = 1;

    QString py = QString::number(value);

      const QString qPath4("shy.tmp");
      QFile qFile4(qPath4);
        if (qFile4.open(QIODevice::WriteOnly)) {
          QTextStream out4(&qFile4);
          out4 << py;
          qFile4.close();
        }


        ui->textBrowser->setTextColor(Qt::green);
        ui->textBrowser->setText("$$ Shield Y position: "+pycs+" cm\n");
        ui->textBrowser->setTextColor(Qt::black);

}


void MainWindow::on_horizontalSlider_5_valueChanged(int value)
{
    ui->horizontalSlider_5->value();

    QString steps = ui->lineEdit_4->text();

    int step = steps.toInt();

    int pyc = (value) * step;

        QString pycs = QString::number(pyc);
      //value = 1;

    QString py = QString::number(value);

      const QString qPath4("shl.tmp");
      QFile qFile4(qPath4);
        if (qFile4.open(QIODevice::WriteOnly)) {
          QTextStream out4(&qFile4);
          out4 << py;
          qFile4.close();
        }


        ui->textBrowser->setTextColor(Qt::green);
        ui->textBrowser->setText("$$ Shield Length: "+pycs+" cm\n");
        ui->textBrowser->setTextColor(Qt::black);
}


void MainWindow::on_horizontalSlider_6_valueChanged(int value)
{
    ui->horizontalSlider_6->value();

    QString steps = ui->lineEdit_4->text();

    int step = steps.toInt();

    int pyc = (value) * step;

        QString pycs = QString::number(pyc);
      //value = 1;

    QString py = QString::number(value);

      const QString qPath4("shw.tmp");
      QFile qFile4(qPath4);
        if (qFile4.open(QIODevice::WriteOnly)) {
          QTextStream out4(&qFile4);
          out4 << py;
          qFile4.close();
        }


        ui->textBrowser->setTextColor(Qt::green);
        ui->textBrowser->setText("$$ Shield Width: "+pycs+" cm\n");
        ui->textBrowser->setTextColor(Qt::black);

}

void MainWindow::on_verticalSlider_4_valueChanged(int value)
{

    int pzc = value;

        QString pzcs = QString::number(pzc);

        ui->textBrowser->setTextColor(Qt::green);

        ui->textBrowser->setText("$$ Shield Z position: "+pzcs+" cm\n");
        ui->textBrowser->setTextColor(Qt::black);

}



void MainWindow::on_pushButton_3_clicked()
{
        QCoreApplication::quit();
}





void MainWindow::on_pushButton_clicked()
{
    //check coordinate input mode
        QString ccmode;
        QFile inputFile491("coordinatemode.tmp");
        if (inputFile491.open(QIODevice::ReadOnly))
        {
          QTextStream inp491(&inputFile491);
          inp491 >> ccmode;
          inputFile491.close();

        }

        if(ccmode=='g')
        {



    QString shieldmat = ui->textEdit_2->toPlainText();
    const QString qPath101("shieldmat.tmp");
        QFile qFile101(qPath101);
          if (qFile101.open(QIODevice::WriteOnly)) {
            QTextStream out101(&qFile101);
            out101 << shieldmat;
            qFile101.close();
          }


          QString shieldrho = ui->lineEdit_5->text();
          const QString qPath102("shieldrho.tmp");
              QFile qFile102(qPath102);
                if (qFile102.open(QIODevice::WriteOnly)) {
                  QTextStream out102(&qFile102);
                  out102 << shieldrho;
                  qFile102.close();
                }



    if(ui->checkBox->isChecked())
    {
        int coord = 1;

        const QString qPath96("coord.tmp");
            QFile qFile96(qPath96);
              if (qFile96.open(QIODevice::WriteOnly)) {
                QTextStream out96(&qFile96);
                out96 << coord;
                qFile96.close();
              }


    }
    else
    {
        int coord = 0;

        const QString qPath96("coord.tmp");
            QFile qFile96(qPath96);
              if (qFile96.open(QIODevice::WriteOnly)) {
                QTextStream out96(&qFile96);
                out96 << coord;
                qFile96.close();
              }

    }

       QString stepsx = ui->lineEdit_4->text();
       const QString qPath20("step.tmp");
           QFile qFile20(qPath20);
             if (qFile20.open(QIODevice::WriteOnly)) {
               QTextStream out20(&qFile20);
               out20 << stepsx;
               qFile20.close();
             }


    QString part = ui->comboBox->currentText();
     const QString qPath9("part.tmp");
         QFile qFile9(qPath9);
           if (qFile9.open(QIODevice::WriteOnly)) {
             QTextStream out9(&qFile9);
             out9 << part;
             qFile9.close();
           }




     QString en = ui->lineEdit->text();
     const QString qPath10("en.tmp");
         QFile qFile10(qPath10);
           if (qFile10.open(QIODevice::WriteOnly)) {
             QTextStream out10(&qFile10);
             out10 << en;
             qFile10.close();
           }

             QString tally = ui->textEdit->toPlainText();

             const QString qPath11("tally.tmp");
         QFile qFile11(qPath11);
           if (qFile11.open(QIODevice::WriteOnly)) {
             QTextStream out11(&qFile11);
             out11 << tally;
             qFile11.close();
           }

   /* a more classical C++ def
       int num_lines = 0;
       string line;
       ifstream myfile("tally.tmp");

       while (!myfile.eof()){
         getline(myfile, line);
                 ++num_lines;
       }
       myfile.close();
       */

       QFile file("tally.tmp");
   int line_count=0;
   file.open(QIODevice::ReadOnly); //| QIODevice::Text)
   QString line[100];
   QTextStream in(&file);
   while( !in.atEnd())
   {
       line[line_count]=in.readLine();
       line_count++;
   }
   file.close();

   //cout << line_count << endl;


                 const QString qPath12("ntally.tmp");
         QFile qFile12(qPath12);
           if (qFile12.open(QIODevice::WriteOnly)) {
             QTextStream out12(&qFile12);
             out12 << line_count;
             qFile12.close();
           }


           QString maxcas = ui->lineEdit_2->text();
           const QString qPath110("maxcas.tmp");
               QFile qFile110(qPath110);
                 if (qFile110.open(QIODevice::WriteOnly)) {
                   QTextStream out110(&qFile110);
                   out110 << maxcas;
                   qFile110.close();
                 }


                 QString maxbch = ui->lineEdit_3->text();
                 const QString qPath111("maxbch.tmp");
                     QFile qFile111(qPath111);
                       if (qFile111.open(QIODevice::WriteOnly)) {
                         QTextStream out111(&qFile111);
                         out111 << maxbch;
                         qFile111.close();
                       }







//******************************************
           QString steps = ui->lineEdit_4->text();

           int step = steps.toInt();

           int value1 = ui->verticalSlider->value();

           int value1x = (value1+100) * step;

           QString sy = QString::number(value1x);

             const QString qPath13("sy.tmp");
             QFile qFile13(qPath13);
               if (qFile13.open(QIODevice::WriteOnly)) {
                 QTextStream out13(&qFile13);
                 out13 << sy;
                 qFile13.close();
               }

               int value2 = ui->horizontalSlider->value();

               int value2x = (value2+100) * step;

               QString sx = QString::number(value2x);


                 const QString qPath14("sx.tmp");
                 QFile qFile14(qPath14);
                   if (qFile14.open(QIODevice::WriteOnly)) {
                     QTextStream out14(&qFile14);
                     out14 << sx;
                     qFile14.close();
                   }


                   int value3 = ui->horizontalSlider_2->value();

                   int value3x = (value3+100) * step;

                   QString px = QString::number(value3x);

                     const QString qPath15("px.tmp");
                     QFile qFile15(qPath15);
                       if (qFile15.open(QIODevice::WriteOnly)) {
                         QTextStream out15(&qFile15);
                         out15 << px;
                         qFile15.close();
                       }

                       int value4 = ui->verticalSlider_2->value();

                       int value4x = (value4+100) * step;

                       QString py = QString::number(value4x);

                         const QString qPath16("py.tmp");
                         QFile qFile16(qPath16);
                           if (qFile16.open(QIODevice::WriteOnly)) {
                             QTextStream out16(&qFile16);
                             out16 << py;
                             qFile16.close();
                           }

                           int col=0;



                          // collision(value1x,value2x,value3x,value4x);
                         //    if(col==1)
                        //   {
                        //       ui->textBrowser->insertPlainText("collision\n");
                        //   }


                           int value5 = ui->verticalSlider_3->value();

                           int value5x = value5;

                           QString sz = QString::number(value5x);

                             const QString qPath17("sz.tmp");
                             QFile qFile17(qPath17);
                               if (qFile17.open(QIODevice::WriteOnly)) {
                                 QTextStream out17(&qFile17);
                                 out17 << sz;
                                 qFile17.close();
                               }







//*****************************************************************
                               if(ui->checkBox_2->isChecked())
                               {
                                   const QString qPath118("shield.tmp");
                                   QFile qFile118(qPath118);
                                     if (qFile118.open(QIODevice::WriteOnly)) {
                                       QTextStream out118(&qFile118);
                                       out118 << "1";
                                       qFile118.close();
                                     }

                                   int value6 = ui->horizontalSlider_3->value();
                                   int value6x = (value6+100) * step;
                                   QString shx = QString::number(value6x);
                                     const QString qPath18("shx.tmp");
                                     QFile qFile18(qPath18);
                                       if (qFile18.open(QIODevice::WriteOnly)) {
                                         QTextStream out18(&qFile18);
                                         out18 << shx;
                                         qFile18.close();
                                       }


                                       int value7 = ui->horizontalSlider_4->value();
                                       int value7x = (value7+100) * step;
                                       QString shy = QString::number(value7x);
                                         const QString qPath19("shy.tmp");
                                         QFile qFile19(qPath19);
                                           if (qFile19.open(QIODevice::WriteOnly)) {
                                             QTextStream out19(&qFile19);
                                             out19 << shy;
                                             qFile19.close();
                                           }


                                           int value8 = ui->horizontalSlider_5->value();
                                           int value8x = (value8) * step;
                                           QString shl = QString::number(value8x);
                                             const QString qPath201("shl.tmp");
                                             QFile qFile201(qPath201);
                                               if (qFile201.open(QIODevice::WriteOnly)) {
                                                 QTextStream out201(&qFile201);
                                                 out201 << shl;
                                                 qFile201.close();
                                               }

                                               int value9 = ui->horizontalSlider_6->value();
                                               int value9x = (value9) * step;
                                               QString shw = QString::number(value9x);
                                                 const QString qPath202("shw.tmp");
                                                 QFile qFile202(qPath202);
                                                   if (qFile202.open(QIODevice::WriteOnly)) {
                                                     QTextStream out202(&qFile202);
                                                     out202 << shw;
                                                     qFile202.close();
                                                   }

                                                   int value57 = ui->verticalSlider_4->value();

                                                   int value57x = value57;

                                                   QString shz = QString::number(value57x);

                                                     const QString qPath157("shz.tmp");
                                                     QFile qFile157(qPath157);
                                                       if (qFile157.open(QIODevice::WriteOnly)) {
                                                         QTextStream out157(&qFile157);
                                                         out157 << shz;
                                                         qFile157.close();
                                                       }
                               }
                               else{
                                   const QString qPath218("shield.tmp");
                                   QFile qFile218(qPath218);
                                     if (qFile218.open(QIODevice::WriteOnly)) {
                                       QTextStream out218(&qFile218);
                                       out218 << "0";
                                       qFile218.close();
                                     }

                               }



                               QString RI = ui->textEdit_3->toPlainText();

                               const QString qPath3("RI.tmp");
                               QFile qFile3(qPath3);
                               if (qFile3.open(QIODevice::WriteOnly)) {
                                     QTextStream out3(&qFile3);
                                     out3 << RI;
                                     qFile3.close();
                               }


                               QString dtime = ui->lineEdit_6->text();

                               const QString qPath4("dtime.tmp");
                               QFile qFile4(qPath4);
                               if (qFile4.open(QIODevice::WriteOnly)) {
                                     QTextStream out4(&qFile4);
                                     out4 << dtime;
                                     qFile4.close();
                               }

                               QString actlow = ui->lineEdit_7->text();

                               const QString qPath5("strength.tmp");
                               QFile qFile5(qPath5);
                               if (qFile5.open(QIODevice::WriteOnly)) {
                                     QTextStream out5(&qFile5);
                                     out5 << actlow;
                                     qFile5.close();
                               }


                               QString projectile = ui->textEdit_4->toPlainText();

                               const QString qPath6("projectile.tmp");
                               QFile qFile6(qPath6);
                               if (qFile6.open(QIODevice::WriteOnly)) {
                                     QTextStream out6(&qFile6);
                                     out6 << projectile;
                                     qFile6.close();
                               }





                               QFile inputFile41("collision.tmp");
                               if (inputFile41.open(QIODevice::ReadOnly))
                               {
                                   QTextStream inp41(&inputFile41);
                                   inp41 >> col;
                                   inputFile41.close();

                               }

                               if(col==1)
                               {

                                   ui->textBrowser->setText("");
                                   ui->textBrowser->setTextColor(Qt::red);

                                   ui->textBrowser->setText("Collision detected!\nSource and/or phantom are too close\nplease consider increasing the distance\nRun Stopped!");


                               }

                               if(col==0)
                               {

                                   ui->textBrowser->setTextColor(Qt::black);

                               ui->textBrowser->setText("");

                               ui->textBrowser->insertPlainText("Running....\n");

                            int systemRet =  system("./run.exe");

                              // int systemRet = system("./run.exe");
                               if(systemRet == -1){
                                        ui->textBrowser->setTextColor(Qt::red);
                                        ui->textBrowser->insertPlainText("Run.exe command failed!\n");
                                       // The system method failed
                               }

                               ui->textBrowser->insertPlainText("Script has been generated\n");

                               ui->textBrowser->insertPlainText("Run Done");
                               }

                               



}

        if(ccmode=='m')
        {
                               QString manualinp = ui->textEdit_5->toPlainText();

                               const QString qPath101("manualinp.tmp");
                               QFile qFile101(qPath101);
                               if (qFile101.open(QIODevice::WriteOnly)) {
                               QTextStream out101(&qFile101);
                               out101 << manualinp;
                               qFile101.close();
                               }

                               if(ui->checkBox->isChecked())
                               {
                               int coord = 1;

                               const QString qPath96("coord.tmp");
                               QFile qFile96(qPath96);
                               if (qFile96.open(QIODevice::WriteOnly)) {
                                        QTextStream out96(&qFile96);
                                        out96 << coord;
                                        qFile96.close();
                               }


                               }
                               else
                               {
                               int coord = 0;

                               const QString qPath96("coord.tmp");
                               QFile qFile96(qPath96);
                               if (qFile96.open(QIODevice::WriteOnly)) {
                                        QTextStream out96(&qFile96);
                                        out96 << coord;
                                        qFile96.close();
                               }

                               }

                               QString stepsx = ui->lineEdit_4->text();
                               const QString qPath20("step.tmp");
                               QFile qFile20(qPath20);
                               if (qFile20.open(QIODevice::WriteOnly)) {
                               QTextStream out20(&qFile20);
                               out20 << stepsx;
                               qFile20.close();
                               }


                               QString part = ui->comboBox->currentText();
                               const QString qPath9("part.tmp");
                               QFile qFile9(qPath9);
                               if (qFile9.open(QIODevice::WriteOnly)) {
                               QTextStream out9(&qFile9);
                               out9 << part;
                               qFile9.close();
                               }




                               QString en = ui->lineEdit->text();
                               const QString qPath10("en.tmp");
                               QFile qFile10(qPath10);
                               if (qFile10.open(QIODevice::WriteOnly)) {
                               QTextStream out10(&qFile10);
                               out10 << en;
                               qFile10.close();
                               }

                               QString tally = ui->textEdit->toPlainText();

                               const QString qPath11("tally.tmp");
                               QFile qFile11(qPath11);
                               if (qFile11.open(QIODevice::WriteOnly)) {
                               QTextStream out11(&qFile11);
                               out11 << tally;
                               qFile11.close();
                               }

                               /* a more classical C++ def
       int num_lines = 0;
       string line;
       ifstream myfile("tally.tmp");

       while (!myfile.eof()){
         getline(myfile, line);
                 ++num_lines;
       }
       myfile.close();
       */

                               QFile file("tally.tmp");
                               int line_count=0;
                               file.open(QIODevice::ReadOnly); //| QIODevice::Text)
                               QString line[100];
                               QTextStream in(&file);
                               while( !in.atEnd())
                               {
                               line[line_count]=in.readLine();
                               line_count++;
                               }
                               file.close();

                               //cout << line_count << endl;


                               const QString qPath12("ntally.tmp");
                               QFile qFile12(qPath12);
                               if (qFile12.open(QIODevice::WriteOnly)) {
                               QTextStream out12(&qFile12);
                               out12 << line_count;
                               qFile12.close();
                               }


                               QString maxcas = ui->lineEdit_2->text();
                               const QString qPath110("maxcas.tmp");
                               QFile qFile110(qPath110);
                               if (qFile110.open(QIODevice::WriteOnly)) {
                               QTextStream out110(&qFile110);
                               out110 << maxcas;
                               qFile110.close();
                               }


                               QString maxbch = ui->lineEdit_3->text();
                               const QString qPath111("maxbch.tmp");
                               QFile qFile111(qPath111);
                               if (qFile111.open(QIODevice::WriteOnly)) {
                               QTextStream out111(&qFile111);
                               out111 << maxbch;
                               qFile111.close();
                               }







                               //******************************************
                               QString steps = ui->lineEdit_4->text();

                               int step = steps.toInt();

                               int value1 = ui->verticalSlider->value();

                               int value1x = (value1+100) * step;

                               QString sy = QString::number(value1x);

                               const QString qPath13("sy.tmp");
                               QFile qFile13(qPath13);
                               if (qFile13.open(QIODevice::WriteOnly)) {
                               QTextStream out13(&qFile13);
                               out13 << sy;
                               qFile13.close();
                               }

                               int value2 = ui->horizontalSlider->value();

                               int value2x = (value2+100) * step;

                               QString sx = QString::number(value2x);


                               const QString qPath14("sx.tmp");
                               QFile qFile14(qPath14);
                               if (qFile14.open(QIODevice::WriteOnly)) {
                               QTextStream out14(&qFile14);
                               out14 << sx;
                               qFile14.close();
                               }


                               int value3 = ui->horizontalSlider_2->value();

                               int value3x = (value3+100) * step;

                               QString px = QString::number(value3x);

                               const QString qPath15("px.tmp");
                               QFile qFile15(qPath15);
                               if (qFile15.open(QIODevice::WriteOnly)) {
                               QTextStream out15(&qFile15);
                               out15 << px;
                               qFile15.close();
                               }

                               int value4 = ui->verticalSlider_2->value();

                               int value4x = (value4+100) * step;

                               QString py = QString::number(value4x);

                               const QString qPath16("py.tmp");
                               QFile qFile16(qPath16);
                               if (qFile16.open(QIODevice::WriteOnly)) {
                               QTextStream out16(&qFile16);
                               out16 << py;
                               qFile16.close();
                               }


                               // collision(value1x,value2x,value3x,value4x);
                               //    if(col==1)
                               //   {
                               //       ui->textBrowser->insertPlainText("collision\n");
                               //   }


                               int value5 = ui->verticalSlider_3->value();

                               int value5x = value5;

                               QString sz = QString::number(value5x);

                               const QString qPath17("sz.tmp");
                               QFile qFile17(qPath17);
                               if (qFile17.open(QIODevice::WriteOnly)) {
                               QTextStream out17(&qFile17);
                               out17 << sz;
                               qFile17.close();
                               }



                               const QString qPath218("shield.tmp");
                               QFile qFile218(qPath218);
                               if (qFile218.open(QIODevice::WriteOnly)) {
                               QTextStream out218(&qFile218);
                               out218 << "0";
                               qFile218.close();
                               }




        QString RI = ui->textEdit_3->toPlainText();

        const QString qPath3("RI.tmp");
        QFile qFile3(qPath3);
        if (qFile3.open(QIODevice::WriteOnly)) {
                               QTextStream out3(&qFile3);
                               out3 << RI;
                               qFile3.close();
        }


        QString dtime = ui->lineEdit_6->text();

        const QString qPath4("dtime.tmp");
        QFile qFile4(qPath4);
        if (qFile4.open(QIODevice::WriteOnly)) {
                               QTextStream out4(&qFile4);
                               out4 << dtime;
                               qFile4.close();
        }

        QString actlow = ui->lineEdit_7->text();

        const QString qPath5("strength.tmp");
        QFile qFile5(qPath5);
        if (qFile5.open(QIODevice::WriteOnly)) {
                               QTextStream out5(&qFile5);
                               out5 << actlow;
                               qFile5.close();
        }


        QString projectile = ui->textEdit_4->toPlainText();

        const QString qPath6("projectile.tmp");
        QFile qFile6(qPath6);
        if (qFile6.open(QIODevice::WriteOnly)) {
                               QTextStream out6(&qFile6);
                               out6 << projectile;
                               qFile6.close();
        }

        ui->textBrowser->setTextColor(Qt::black);

        ui->textBrowser->setText("");

            int systemRet14 =  system("./manlinec.exe");

        if(systemRet14 == -1){
                               ui->textBrowser->setTextColor(Qt::red);
                               ui->textBrowser->insertPlainText("manualentry.exe command failed!\n");
                               // The system method failed
        }


        ui->textBrowser->insertPlainText("Running....\n");

        int systemRet4 =  system("./manualentry.exe");

        if(systemRet4 == -1){
                               ui->textBrowser->setTextColor(Qt::red);
                               ui->textBrowser->insertPlainText("manualentry.exe command failed!\n");
                               // The system method failed
        }

        ui->textBrowser->insertPlainText("Script has been generated\n");

        ui->textBrowser->insertPlainText("Run Done");

            int systemRet24 =  system("./pointsfind.exe");

        if(systemRet24 == -1){
                               ui->textBrowser->setTextColor(Qt::red);
                               ui->textBrowser->insertPlainText("pointsfind.exe command failed!\n");
                               // The system method failed
        }


          int systemRet124 =  system("./inputparser.exe");

        if(systemRet124 == -1){
                               ui->textBrowser->setTextColor(Qt::red);
                               ui->textBrowser->insertPlainText("inputparser.exe command failed!\n");
                               // The system method failed
        }


        }

        ui->pushButton_5->click();

        ui->pushButton_5->released();

        }


//*******************************************
    /*
       int sy1 = ui->verticalSlider->value();
        QString sy = QString::number(sy1);
          const QString qPath1("sy.tmp");
          QFile qFile1(qPath1);
            if (qFile1.open(QIODevice::WriteOnly)) {
              QTextStream out1(&qFile1);
              out1 << sy;
              qFile1.close();
            }
             int sx1 = ui->verticalSlider->value();
            QString sx = QString::number(sx1);
              const QString qPath2("sx.tmp");
              QFile qFile2(qPath2);
                if (qFile2.open(QIODevice::WriteOnly)) {
                  QTextStream out2(&qFile2);
                  out2 << sx;
                  qFile2.close();
                }
                int px1 = ui->verticalSlider->value();
                QString px = QString::number(px1);
                  const QString qPath3("px.tmp");
                  QFile qFile3(qPath3);
                    if (qFile3.open(QIODevice::WriteOnly)) {
                      QTextStream out3(&qFile3);
                      out3 << px;
                      qFile3.close();
                    }
                int py1 = ui->verticalSlider->value();
                    QString py = QString::number(py1);
                      const QString qPath4("py.tmp");
                      QFile qFile4(qPath4);
                        if (qFile4.open(QIODevice::WriteOnly)) {
                          QTextStream out4(&qFile4);
                          out4 << py;
                          qFile4.close();
                        }


                               QString runvals;


                                QFile inputFile411("runphits.bat");
                               if (inputFile411.open(QIODevice::ReadOnly))
                               {
                               QTextStream inp411(&inputFile411);
                               runvals = inp411.readAll();
                               inputFile411.close();

                               }

                               qDebug() << runvals;

*/






void MainWindow::on_verticalSlider_3_valueChanged(int value)
{
   // QString steps = ui->lineEdit_4->text();

  //  int step = steps.toInt();

    int pzc = value;

        QString pzcs = QString::number(pzc);

        ui->textBrowser->setTextColor(Qt::red);

        ui->textBrowser->setText(">> Source Z position: "+pzcs+" cm\n");
        ui->textBrowser->setTextColor(Qt::black);


}


void MainWindow::on_pushButton_4_clicked()
{
    ui->textBrowser->setTextColor(Qt::blue);
    ui->textBrowser->setText("");
    ui->textBrowser->insertPlainText("Developed at CYRIC, Tohoku University, Japan\n");
    ui->textBrowser->insertPlainText("By: Mehrdad S.Beni, Hiroshi Watabe, Peter K.N. Yu\n");
    ui->textBrowser->insertPlainText("Please report any bugs or issues to:\nben.sh@tohoku.ac.jp  or  ben.sh@my.cityu.edu.hk");
    ui->textBrowser->setTextColor(Qt::black);
}


void MainWindow::on_pushButton_2_clicked()
{

    int systemRet = system("./ScriptShow");

    //int systemRet = system("./ScriptShow");
    if(systemRet == -1){
                               ui->textBrowser->setTextColor(Qt::red);
                               ui->textBrowser->insertPlainText("ScriptShow command failed!\n");
                               // The system method failed
    }

}







void MainWindow::on_pushButton_5_clicked()
{

    QString steps = ui->lineEdit_4->text();


    int value1 = ui->verticalSlider->value();

    int value1x = value1;

    QString sy = QString::number(value1x);

      const QString qPath13("sy.tmp");
      QFile qFile13(qPath13);
        if (qFile13.open(QIODevice::WriteOnly)) {
          QTextStream out13(&qFile13);
          out13 << sy;
          qFile13.close();
        }

        int value2 = ui->horizontalSlider->value();

        int value2x = value2;

        QString sx = QString::number(value2x);


          const QString qPath14("sx.tmp");
          QFile qFile14(qPath14);
            if (qFile14.open(QIODevice::WriteOnly)) {
              QTextStream out14(&qFile14);
              out14 << sx;
              qFile14.close();
            }


            int value3 = ui->horizontalSlider_2->value();

            int value3x = value3;

            QString px = QString::number(value3x);

              const QString qPath15("px.tmp");
              QFile qFile15(qPath15);
                if (qFile15.open(QIODevice::WriteOnly)) {
                  QTextStream out15(&qFile15);
                  out15 << px;
                  qFile15.close();
                }

                int value4 = ui->verticalSlider_2->value();

                int value4x = value4;

                QString py = QString::number(value4x);

                  const QString qPath16("py.tmp");
                  QFile qFile16(qPath16);
                    if (qFile16.open(QIODevice::WriteOnly)) {
                      QTextStream out16(&qFile16);
                      out16 << py;
                      qFile16.close();
                    }


                    int value5 = ui->verticalSlider_3->value();

                    int value5x = value5;

                    QString sz = QString::number(value5x);

                      const QString qPath17("sz.tmp");
                      QFile qFile17(qPath17);
                        if (qFile17.open(QIODevice::WriteOnly)) {
                          QTextStream out17(&qFile17);
                          out17 << sz;
                          qFile17.close();
                        }
//*****************************************************************
                        if(ui->checkBox_2->isChecked())
                        {
                            const QString qPath118("shield.tmp");
                            QFile qFile118(qPath118);
                              if (qFile118.open(QIODevice::WriteOnly)) {
                                QTextStream out118(&qFile118);
                                out118 << "1";
                                qFile118.close();
                              }

                            int value6 = ui->horizontalSlider_3->value();
                            int value6x = value6;
                            QString shx = QString::number(value6x);
                              const QString qPath18("shx.tmp");
                              QFile qFile18(qPath18);
                                if (qFile18.open(QIODevice::WriteOnly)) {
                                  QTextStream out18(&qFile18);
                                  out18 << shx;
                                  qFile18.close();
                                }


                                int value7 = ui->horizontalSlider_4->value();
                                int value7x = value7;
                                QString shy = QString::number(value7x);
                                  const QString qPath19("shy.tmp");
                                  QFile qFile19(qPath19);
                                    if (qFile19.open(QIODevice::WriteOnly)) {
                                      QTextStream out19(&qFile19);
                                      out19 << shy;
                                      qFile19.close();
                                    }


                                    int value8 = ui->horizontalSlider_5->value();
                                    int value8x = value8;
                                    QString shl = QString::number(value8x);
                                      const QString qPath201("shl.tmp");
                                      QFile qFile201(qPath201);
                                        if (qFile201.open(QIODevice::WriteOnly)) {
                                          QTextStream out201(&qFile201);
                                          out201 << shl;
                                          qFile201.close();
                                        }

                                        int value9 = ui->horizontalSlider_6->value();
                                        int value9x = value9;
                                        QString shw = QString::number(value9x);
                                          const QString qPath202("shw.tmp");
                                          QFile qFile202(qPath202);
                                            if (qFile202.open(QIODevice::WriteOnly)) {
                                              QTextStream out202(&qFile202);
                                              out202 << shw;
                                              qFile202.close();
                                            }

                                            int value57 = ui->verticalSlider_4->value();

                                            int value57x = value57;

                                            QString shz = QString::number(value57x);

                                              const QString qPath157("shz.tmp");
                                              QFile qFile157(qPath157);
                                                if (qFile157.open(QIODevice::WriteOnly)) {
                                                  QTextStream out157(&qFile157);
                                                  out157 << shz;
                                                  qFile157.close();
                                                }
                        }
                        else{
                            const QString qPath218("shield.tmp");
                            QFile qFile218(qPath218);
                              if (qFile218.open(QIODevice::WriteOnly)) {
                                QTextStream out218(&qFile218);
                                out218 << "0";
                                qFile218.close();
                              }

                        }


}


void MainWindow::on_checkBox_2_clicked()
{

    if(ui->checkBox_2->isChecked())
    {
        const QString qPath118("shield.tmp");
        QFile qFile118(qPath118);
          if (qFile118.open(QIODevice::WriteOnly)) {
            QTextStream out118(&qFile118);
            out118 << "1";
            qFile118.close();
          }
    }
    else
    {
        const QString qPath118("shield.tmp");
        QFile qFile118(qPath118);
          if (qFile118.open(QIODevice::WriteOnly)) {
            QTextStream out118(&qFile118);
            out118 << "0";
            qFile118.close();
          }
    }

}


void MainWindow::on_pushButton_6_clicked()
{


    ui->lineEdit->setVisible(false);

    ui->label_2->setVisible(false);

    ui->comboBox->setVisible(false);

        ui->label->setVisible(false);

        ui->textEdit_3->setVisible(true);

        ui->label_16->setVisible(true);

        ui->lineEdit_6->setVisible(true);
        ui->lineEdit_7->setVisible(true);

        ui->label_17->setVisible(true);
        ui->label_18->setVisible(true);

        ui->textEdit_4->setVisible(true);

        ui->label_19->setVisible(true);

        ui->textEdit_3->setText("Cs-137");

        ui->lineEdit_6->setText("-10.0");

        ui->lineEdit_7->setText("100.0");

        ui->textEdit_4->setText("photon");

         ui->textEdit->setText("photon");





        const QString qPath2("dymcmode.tmpz");
        QFile qFile2(qPath2);
          if (qFile2.open(QIODevice::WriteOnly)) {
            QTextStream out2(&qFile2);
            out2 << "RI";
            qFile2.close();
          }











}


void MainWindow::on_pushButton_7_clicked()
{


    ui->lineEdit->setVisible(true);

    ui->label_2->setVisible(true);

    ui->comboBox->setVisible(true);

        ui->label->setVisible(true);

        ui->textEdit_3->setVisible(false);

        ui->label_16->setVisible(false);

        ui->lineEdit_6->setVisible(false);
        ui->lineEdit_7->setVisible(false);

        ui->label_17->setVisible(false);
        ui->label_18->setVisible(false);

        ui->textEdit_4->setVisible(false);

        ui->label_19->setVisible(false);

        ui->comboBox->addItem("proton");
        ui->comboBox->addItem("neutron");
        ui->comboBox->addItem("photon");
        ui->comboBox->addItem("alpha");

        ui->lineEdit->setText("80");

        ui->textEdit->setText("proton\nneutron");

        const QString qPath2("dymcmode.tmpz");
        QFile qFile2(qPath2);
          if (qFile2.open(QIODevice::WriteOnly)) {
            QTextStream out2(&qFile2);
            out2 << "P";
            qFile2.close();
          }

}


void MainWindow::on_pushButton_8_clicked()
{

          ui->textBrowser->setText("");
          ui->textBrowser->setTextColor(Qt::black);
     //     ui->textBrowser->insertPlainText("Running PHITS, please wait...\n");

          int systemRet2 = system("./sumtally.exe");
         // int systemRet = system("sh runphits.bat");
          if(systemRet2 == -1){
            ui->textBrowser->setTextColor(Qt::red);
            ui->textBrowser->insertPlainText("sumtally.exe command failed!\n");
            // The system method failed
          }


        int systemRet = system("sh runphits.bat");
         // int systemRet = system("sh runphits.bat");
          if(systemRet == -1){
            ui->textBrowser->setTextColor(Qt::red);
            ui->textBrowser->insertPlainText("sh runphits.bat command failed!\n");
            // The system method failed
          }

           ui->textBrowser->insertPlainText("PHITS Run completed!\n");
            ui->textBrowser->insertPlainText("your results were saved in working_directory\n");

}


void MainWindow::on_pushButton_9_clicked()
{
            ui->openGLWidget->setVisible(false);
            ui->horizontalSlider->setVisible(false);
            ui->horizontalSlider_2->setVisible(false);
            ui->verticalSlider->setVisible(false);
            ui->verticalSlider_2->setVisible(false);

            ui->textEdit_5->setVisible(true);
            ui->label_20->setVisible(true);
            ui->pushButton_11->setVisible(true);

            ui->textEdit_5->setText("");


            ui->textEdit_5->insertPlainText("sx,sy,sz,px,py\n");
            ui->textEdit_5->insertPlainText("60,120,70,30,75\n");
            ui->textEdit_5->insertPlainText("60,120,70,65,75\n");
            ui->textEdit_5->insertPlainText("60,120,70,90,75\n");
            ui->textEdit_5->insertPlainText("60,120,70,145,75\n");

            const QString qPath2("coordinatemode.tmp");
            QFile qFile2(qPath2);
            if (qFile2.open(QIODevice::WriteOnly)) {
            QTextStream out2(&qFile2);
            out2 << "m";
            qFile2.close();
            }


}


void MainWindow::on_pushButton_10_clicked()
{
            ui->openGLWidget->setVisible(true);
            ui->horizontalSlider->setVisible(true);
            ui->horizontalSlider_2->setVisible(true);
            ui->verticalSlider->setVisible(true);
            ui->verticalSlider_2->setVisible(true);

            ui->textEdit_5->setVisible(false);
            ui->label_20->setVisible(false);
            ui->pushButton_11->setVisible(false);


            const QString qPath2("coordinatemode.tmp");
            QFile qFile2(qPath2);
            if (qFile2.open(QIODevice::WriteOnly)) {
            QTextStream out2(&qFile2);
            out2 << "g";
            qFile2.close();
            }

}


void MainWindow::on_pushButton_11_clicked()
{

            int systemRet = system("./CyricPositionPlotter");
            if(systemRet == -1){
            ui->textBrowser->setTextColor(Qt::red);
            ui->textBrowser->insertPlainText("CyricPositionPlotter command failed!\n");
            // The system method failed
            }


}

