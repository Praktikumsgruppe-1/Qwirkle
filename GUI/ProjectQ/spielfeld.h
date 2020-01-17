#ifndef SPIELFELD_H
#define SPIELFELD_H

#include <QFrame>
#include <QPixmap>
#include "undo.h"
//#include <QLabel>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

class Spielfeld : public QFrame
{
public:
    explicit Spielfeld(QWidget *parent = nullptr);

    friend class undoClass;

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // SPIELFELD_H
