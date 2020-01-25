#include "mainwindow.h"

#include <QApplication>
#include <qglobal.h>
#include <QTime>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Create seed for the random
    // That is needed only once on application startup
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    //qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    w.show();
    return a.exec();
}
