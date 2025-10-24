#ifndef TALLYPLOT_H
#define TALLYPLOT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class tallyplot; }
QT_END_NAMESPACE

class tallyplot : public QMainWindow
{
    Q_OBJECT

public:
    tallyplot(QWidget *parent = nullptr);
    ~tallyplot();
    void addPointlerr(double x, double y);
    void addPointdose(double x, double y);
    void addPointuerr(double x, double y);
    void clearData();
    void plot();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::tallyplot *ui;
    QVector<double> qv_x,qv_y;
    QVector<double> sv_x,sv_y;
    QVector<double> dv_x,dv_y;
};
#endif // TALLYPLOT_H
