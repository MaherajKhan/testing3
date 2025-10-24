#include "cyricpositionplotter.h"
#include "ui_cyricpositionplotter.h"
#include <iostream>

using namespace std;

cyricpositionplotter::cyricpositionplotter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cyricpositionplotter)
{
    ui->setupUi(this);

    ui->plot->addGraph();

    ui->plot->setBackground(QColor(200,200,200,20));

  // ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssPeace,16));
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine);

    ui->plot->addGraph();
    ui->plot->graph(1)->setPen(QPen(QColor(255,10,0)));

    //ui->plot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
        ui->plot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssStar,16));
    ui->plot->graph(1)->setLineStyle(QCPGraph::lsNone);

    ui->plot->graph(0)->setName("phantom");
    ui->plot->graph(1)->setName("source");

    ui->plot->legend->setVisible(true);

    ui->lcdNumber->setPalette(Qt::blue);




    ui->plot->xAxis->setLabel("x coordinate (cm)");
    ui->plot->yAxis->setLabel("y coordinate (cm)");


    double range[2];
    QFile inputFile15("maxvalues.tmp");
    if (inputFile15.open(QIODevice::ReadOnly))
    {
        QTextStream inp15(&inputFile15);
        for (int i=0; i < 2; i++)
        {
            inp15 >> range[i];
        }

        inputFile15.close();

    }


    ui->plot->xAxis->setRange(0,range[0]+80); //the upper range must be set to max val
    ui->plot->yAxis->setRange(0,range[1]+80); //the upper range must be set to max val



   // ui->plot->axisRect(0)->axis(QCPAxis::atLeft)->rescale();
   // ui->plot->axisRect(0)->axis(QCPAxis::atBottom)->rescale();
}

cyricpositionplotter::~cyricpositionplotter()
{
    delete ui;
}

void cyricpositionplotter::addPoint(double x, double y)
{

    qv_x.append(x);
    qv_y.append(y);


}

void cyricpositionplotter::addPointsource(double x, double y)
{

    sv_x.append(x);
    sv_y.append(y);

}

void cyricpositionplotter::clearData()
{

    qv_x.clear();
    qv_y.clear();

    sv_x.clear();
    sv_y.clear();




}

void cyricpositionplotter::plot()
{


    ui->plot->graph(0)->setData(qv_x,qv_y);

    ui->plot->graph(1)->setData(sv_x,sv_y);

    ui->plot->replot();

   // ui->plot->axisRect(0)->axis(QCPAxis::atLeft)->rescale();
  //  ui->plot->axisRect(0)->axis(QCPAxis::atBottom)->rescale();

    ui->plot->update();

}


       int posnum;

   //    double sy[posnum];
   //    double px[posnum];
    //   double py[posnum];

       int iter=0;
void cyricpositionplotter::on_pushButton_clicked()
{

     clearData();

    QFile inputFile1("manlines.tmp");
    if (inputFile1.open(QIODevice::ReadOnly))
    {
        QTextStream inp1(&inputFile1);
        inp1 >> posnum;
        inputFile1.close();

    }

     double data[posnum][4];

    QFile inputFile10("dataplot.tmp");
    if (inputFile10.open(QIODevice::ReadOnly))
    {
        QTextStream inp10(&inputFile10);
        for(int i=0; i < posnum; i++)
        {
          for(int j=0; j < 4; j++)
          {
               inp10 >> data[i][j];
          }

        }


        inputFile10.close();

    }



    addPoint(data[iter][2],data[iter][3]);

    addPointsource(data[iter][0],data[iter][1]);

    ui->lcdNumber->display(iter+1);


   // ui->plot->axisRect(0)->axis(QCPAxis::atLeft)->rescale();
  //  ui->plot->axisRect(0)->axis(QCPAxis::atBottom)->rescale();

    plot();

    if(iter < posnum-1)
    {
        iter++;

    }
    else{
        iter=0;
    }




}


void cyricpositionplotter::on_pushButton_3_clicked()
{
     QCoreApplication::quit();
}

