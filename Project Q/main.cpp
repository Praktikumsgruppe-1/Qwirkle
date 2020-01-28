/**********************************************************************/
// Datei: main.h
// Die main Funktion startet die Anwendung.
/**********************************************************************/

#include <QApplication>
#include <qglobal.h>
#include <QTime>

#include "mainwindow.h"
#include "game.h"


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
