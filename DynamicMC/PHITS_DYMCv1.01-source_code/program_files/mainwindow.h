#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class GLWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void on_horizontalSlider_valueChanged(int value);
      void on_verticalSlider_valueChanged(int value);
     // int col = 0;



private slots:
      void on_horizontalSlider_2_valueChanged(int value);

      void on_verticalSlider_2_valueChanged(int value);

      void on_pushButton_3_clicked();

      void on_pushButton_clicked();

      void on_verticalSlider_3_valueChanged(int value);

      void on_pushButton_4_clicked();
     // void collision(int sx, int sy, int px, int py);

      void on_pushButton_2_clicked();

      void on_horizontalSlider_3_valueChanged(int value);

      void on_horizontalSlider_4_valueChanged(int value);

      void on_horizontalSlider_5_valueChanged(int value);

      void on_horizontalSlider_6_valueChanged(int value);

      void on_verticalSlider_4_valueChanged(int value);

      void on_pushButton_5_clicked();

      void on_checkBox_2_clicked();

      void on_pushButton_6_clicked();

      void on_pushButton_7_clicked();

      void on_pushButton_8_clicked();

      void on_pushButton_9_clicked();

      void on_pushButton_10_clicked();

      void on_pushButton_11_clicked();

  private:
    Ui::MainWindow *ui;
   // GLWidget *glwin;



};
#endif // MAINWINDOW_H
