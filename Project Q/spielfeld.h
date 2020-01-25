#ifndef SPIELFELD_H
#define SPIELFELD_H

#include <QFrame>
#include <QPixmap>
//#include <QLabel>

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
    int SteinImFeld = 0;

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    friend class Game;
};

#endif // SPIELFELD_H
