#ifndef TAUSCHEN_H
#define TAUSCHEN_H

#include <QFrame>

class Game;

class Tauschen : public QFrame
{
public:
    explicit Tauschen(QWidget *parent = nullptr);
    void SteinTauschen();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
};

#endif // TAUSCHEN_H
