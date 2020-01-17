#include "benutzerhand.h"
#include "undo.h"

#include <QtWidgets>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QFrame>
#include <QPicture>
#include <QPixmap>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <string>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QRandomGenerator>


#include <QGlobal.h>
#include <QTime>

Benutzerhand::Benutzerhand(QWidget *parent, int a, int b)
    : QFrame(parent)
{
    setMinimumSize(20, 20);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);

    QPixmap blau_eckig (QPixmap(":/images/blau_eckig.png"));
    QPixmap blau_kreuz (QPixmap(":/images/blau_kreuz.png"));
    QPixmap blau_raute (QPixmap(":/images/blau_raute.png"));
    QPixmap blau_rund (QPixmap(":/images/blau_rund.png"));
    QPixmap blau_sonne (QPixmap(":/images/blau_sonne.png"));
    QPixmap blau_stern (QPixmap(":/images/blau_stern.png"));

    QPixmap gelb_eckig (QPixmap(":/images/gelb_eckig.png"));
    QPixmap gelb_kreuz (QPixmap(":/images/gelb_kreuz.png"));
    QPixmap gelb_raute (QPixmap(":/images/gelb_raute.png"));
    QPixmap gelb_rund (QPixmap(":/images/gelb_rund.png"));
    QPixmap gelb_sonne (QPixmap(":/images/gelb_sonne.png"));
    QPixmap gelb_stern (QPixmap(":/images/gelb_stern.png"));

    QPixmap gruen_eckig (QPixmap(":/images/gruen_eckig.png"));
    QPixmap gruen_kreuz (QPixmap(":/images/gruen_kreuz.png"));
    QPixmap gruen_raute (QPixmap(":/images/gruen_raute.png"));
    QPixmap gruen_sonne (QPixmap(":/images/gruen_sonne.png"));
    QPixmap gruen_rund (QPixmap(":/images/gruen_rund.png"));
    QPixmap gruen_stern (QPixmap(":/images/gruen_stern.png"));

    QPixmap lila_eckig (QPixmap(":/images/lila_eckig.png"));
    QPixmap lila_kreuz (QPixmap(":/images/lila_kreuz.png"));
    QPixmap lila_raute (QPixmap(":/images/lila_raute.png"));
    QPixmap lila_rund (QPixmap(":/images/lila_rund.png"));
    QPixmap lila_sonne (QPixmap(":/images/lila_sonne.png"));
    QPixmap lila_stern (QPixmap(":/images/lila_stern.png"));

    QPixmap orange_eckig (QPixmap(":/images/orange_eckig.png"));
    QPixmap orange_kreuz (QPixmap(":/images/orange_kreuz.png"));
    QPixmap orange_raute (QPixmap(":/images/orange_raute.png"));
    QPixmap orange_rund (QPixmap(":/images/orange_rund.png"));
    QPixmap orange_sonne (QPixmap(":/images/orange_sonne.png"));
    QPixmap orange_stern (QPixmap(":/images/orange_stern.png"));

    QPixmap rot_eckig (QPixmap(":/images/rot_eckig.png"));
    QPixmap rot_kreuz (QPixmap(":/images/rot_kreuz.png"));
    QPixmap rot_raute (QPixmap(":/images/rot_raute.png"));
    QPixmap rot_rund (QPixmap(":/images/rot_rund.png"));
    QPixmap rot_sonne (QPixmap(":/images/rot_sonne.png"));
    QPixmap rot_stern (QPixmap(":/images/rot_stern.png"));



    QPixmap stein[6][6] =
    {
       {blau_eckig, blau_kreuz, blau_raute, blau_rund, blau_sonne, blau_stern},
       {gelb_eckig, gelb_kreuz, gelb_raute, gelb_rund, gelb_sonne, gelb_stern},
       {gruen_eckig, gruen_kreuz, gruen_raute, gruen_rund, gruen_sonne, gruen_stern},
       {lila_eckig, lila_kreuz, lila_raute, lila_rund, lila_sonne, lila_stern},
       {orange_eckig, orange_kreuz, orange_raute, orange_rund, orange_sonne, orange_stern},
       {rot_eckig, rot_kreuz, rot_raute, rot_rund, rot_sonne, rot_stern}
    };


    QLabel *stein1Icon = new QLabel(this);
    stein1Icon->setPixmap(QPixmap(stein[a][b]));
    stein1Icon->move(2, 2);
    stein1Icon->show();
    stein1Icon->setAttribute(Qt::WA_DeleteOnClose);

}

void Benutzerhand::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Benutzerhand::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Benutzerhand::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pixmap);
        newIcon->move(event->pos() - offset);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        undoClass::undoStack.push( newIcon );
        undoClass::undoCoordNewX.push( newIcon->x() );
        undoClass::undoCoordNewY.push( newIcon->y() );

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Benutzerhand::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if (!child)
        return;

    QPixmap pixmap = *child->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - child->pos());

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());

    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    child->setPixmap(tempPixmap);

    undoClass::undoParent.push( this );
    undoClass::undoCoordOldX.push( child->geometry().x() );
    undoClass::undoCoordOldY.push( child->geometry().y() );
    undoClass::undoPixmap.push( *(child->pixmap()) );


    if (drag->exec(Qt::MoveAction) == Qt::MoveAction) {
        child->close();
    } else {
        child->show();
        child->setPixmap(pixmap);
    }
}

//die extern definierte Funktion zum randomizen der Stein_Zahlen für das Benutzerhand

extern int randInt(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}
