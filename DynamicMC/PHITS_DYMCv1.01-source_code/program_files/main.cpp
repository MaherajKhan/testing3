#include "mainwindow.h"
#include <QApplication>
#include <QSurfaceFormat>

int main(int argc, char *argv[])
{
   // QSurfaceFormat fmt;
   // fmt.setVersion(4,0);
   // QSurfaceFormat::setDefaultFormat(fmt);


    QApplication a(argc, argv);
    MainWindow w;
     w.setWindowIcon(QIcon("icon.ico"));
    w.show();
    return a.exec();
}
