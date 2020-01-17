#ifndef TAUSCHEN_H
#define TAUSCHEN_H

#include "undo.h"
#include "game.h"
#include <QFrame>

class Tauschen : public QFrame
{
public:
    explicit Tauschen(QWidget *parent = nullptr);
    void SteinTauschen();

protected:
    void dropEvent(QDropEvent *event) override;

};

#endif // TAUSCHEN_H
