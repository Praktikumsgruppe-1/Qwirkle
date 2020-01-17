#ifndef TAUSCHEN_H
#define TAUSCHEN_H

#include "undo.h"
#include "game.h"
#include <QFrame>

class Tauschen : public QFrame
{
public:
    Tauschen(QWidget *parent);
    void SteinTauschen();

protected:
    //void dragEnterEvent(QDragEnterEvent *event) override;
    //void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    //void mousePressEvent(QMouseEvent *event) override;

};

#endif // TAUSCHEN_H
