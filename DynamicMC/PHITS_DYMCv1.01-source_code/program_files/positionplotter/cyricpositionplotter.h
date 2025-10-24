#ifndef CYRICPOSITIONPLOTTER_H
#define CYRICPOSITIONPLOTTER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class cyricpositionplotter; }
QT_END_NAMESPACE

class cyricpositionplotter : public QMainWindow
{
    Q_OBJECT

public:
    cyricpositionplotter(QWidget *parent = nullptr);
    ~cyricpositionplotter();

    void addPoint(double x, double y);
    void addPointsource(double x, double y);
    void clearData();
    void plot();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::cyricpositionplotter *ui;

    QVector<double> qv_x,qv_y;
    QVector<double> sv_x,sv_y;
};
#endif // CYRICPOSITIONPLOTTER_H
