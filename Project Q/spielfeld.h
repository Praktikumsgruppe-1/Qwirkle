/**********************************************************************/
// Datei: spielfeld.h
// Die Klasse Spielfeld enthaelt ein QFrame, mit dem die einzelnen Felder
// auf dem Spielfeld erstellt werden, die mit Drop Funktion ausgestattet
// sind.))
/**********************************************************************/
#ifndef SPIELFELD_H
#define SPIELFELD_H

#include <QFrame>
#include <QPixmap>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class Spielfeld : public QFrame
{
public:
    explicit Spielfeld(QWidget *parent = nullptr, int spalteX = 0, int reiheY = 0 );
    int reihe;
    int spalte;

    void feldArrayZuruecksetzen( );

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

    friend class Game;
};

extern int SteinImFeld;             // erster Stein der Zugrunde, wäre = 0
#endif // SPIELFELD_H
