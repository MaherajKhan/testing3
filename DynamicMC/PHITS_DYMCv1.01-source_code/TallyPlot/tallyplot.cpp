#include "tallyplot.h"
#include "ui_tallyplot.h"
#include <iostream>

using namespace std;

tallyplot::tallyplot(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tallyplot)
{
    ui->setupUi(this);

    ui->plot->addGraph();

    ui->plot->setBackground(QColor(200,200,200,20));

    // ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle,8));
    ui->plot->graph(0)->setPen(QPen(QColor(255,10,0)));
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);

    ui->plot->addGraph();
    ui->plot->graph(1)->setPen(QPen(QColor(255,10,0)));

    //ui->plot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
    ui->plot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle,8));
    ui->plot->graph(1)->setLineStyle(QCPGraph::lsNone);

    ui->plot->addGraph();
    ui->plot->graph(2)->setPen(QPen(QColor(0,10,255)));

    //ui->plot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
    ui->plot->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssStar,12));
    ui->plot->graph(2)->setLineStyle(QCPGraph::lsLine);





    ui->lineEdit->setText("YourOrganTallyPath.out");

    // QString part = ui->lineEdit->text();

    //   ui->plot->plotLayout()->insertRow(0);
    //   ui->plot->plotLayout()->addElement(0, 0, new QCPTextElement(ui->plot, part, QFont("sans", 12, QFont::Bold)));





    ui->plot->xAxis->setLabel("L-lung     R-lung    Heart&    Spine&   Brain    Head&");
    ui->plot->yAxis->setLabel("Dose (Mono E: Gy/source, RI: Gy/sec)");






    // ui->plot->axisRect(0)->axis(QCPAxis::atLeft)->rescale();
    // ui->plot->axisRect(0)->axis(QCPAxis::atBottom)->rescale();
}

tallyplot::~tallyplot()
{
    delete ui;
}

void tallyplot::addPointlerr(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
}

void tallyplot::addPointdose(double x, double y)
{
    dv_x.append(x);
    dv_y.append(y);
}

void tallyplot::addPointuerr(double x, double y)
{
    sv_x.append(x);
    sv_y.append(y);
}

void tallyplot::clearData()
{
    qv_x.clear();
    qv_y.clear();

    sv_x.clear();
    sv_y.clear();

    dv_x.clear();
    dv_y.clear();
}

void tallyplot::plot()
{
    ui->plot->graph(0)->setData(qv_x,qv_y);

    ui->plot->graph(1)->setData(sv_x,sv_y);

    ui->plot->graph(2)->setData(dv_x,dv_y);

    ui->plot->replot();

    ui->plot->update();
}

int posnum =6;
int iter=0;
void tallyplot::on_pushButton_clicked()
{
    clearData();

    // ui->plot->graph(0)->setName("");

    ui->plot->graph(2)->setName("average dose");
    ui->plot->graph(0)->removeFromLegend();
    ui->plot->graph(1)->removeFromLegend();

    //  ui->plot->graph(1)->setName("dose+err");


    ui->plot->legend->setVisible(true);

    QString part = ui->lineEdit->text();

    const QString qPath1("sumtalpart.tmp");
    QFile qFile1(qPath1);
    if (qFile1.open(QIODevice::WriteOnly)) {
        QTextStream out1(&qFile1);
        out1 << part;
        qFile1.close();
    }

    int systemRet = system("./searchtally.exe");
    if(systemRet == -1){
        cout << "searchtally.exe command failed!" << endl;
        // The system method failed
    }

    int systemRet2 = system("./sumtallyparser.exe");
    if(systemRet2 == -1){
        cout << "sumtallyparser.exe command failed!" << endl;
        // The system method failed
    }

    double range=0;
    QFile inputFile15("maxy.tmp");
    if (inputFile15.open(QIODevice::ReadOnly))
    {
        QTextStream inp15(&inputFile15);
        inp15 >> range;
        inputFile15.close();

    }


    ui->plot->xAxis->setRange(0,7); //the upper range must be set to max val
    ui->plot->yAxis->setRange(0,range+(range/10.0)); //the upper range must be set to max val

    //  ui->plot->plotLayout()->insertRow(0);
    //  ui->plot->plotLayout()->addElement(0, 0, new QCPTextElement(ui->plot, part, QFont("sans", 12, QFont::Bold)));



    double data[posnum][4];

    QFile inputFile10("plotsumtally.tmp");
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

    for(int iter=0; iter < 6; iter++)
    {
        addPointlerr(data[iter][0],data[iter][1]);

        addPointdose(data[iter][0],data[iter][2]);

        addPointuerr(data[iter][0],data[iter][3]);
    }



    // ui->lcdNumber->display(iter+1);


    // ui->plot->axisRect(0)->axis(QCPAxis::atLeft)->rescale();
    //  ui->plot->axisRect(0)->axis(QCPAxis::atBottom)->rescale();

    plot();

    int systemRet3 = system("rm *.tmp");
    if(systemRet3 == -1){
        cout << "searchtally.exe command failed!" << endl;
        // The system method failed
    }
}


void tallyplot::on_pushButton_2_clicked()
{
    QCoreApplication::quit();
}

