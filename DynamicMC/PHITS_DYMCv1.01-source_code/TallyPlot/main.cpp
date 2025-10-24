#include "tallyplot.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tallyplot w;
    w.show();
    return a.exec();
}
