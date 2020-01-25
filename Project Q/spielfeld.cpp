#include "spielfeld.h"
#include "undo.h"
#include "regeln.h"
#include "benutzerhand.h"
#include "game.h"

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
#include <QtWidgets>

#include <qglobal.h>
#include <QTime>


// Spielfeld ist die Klasse für ein drag widget, aber ohne das darin Steine mit drin sind, beim aufrufen
// es ist das normale Spielfeld, aber noch nicht mit den festen Punkten

Spielfeld::Spielfeld(QWidget *parent, int spalteX, int reiheY )
    : QFrame(parent), reihe( reiheY ), spalte( spalteX )
{
    setMinimumSize(75, 75);
    setMaximumSize(200,200);
    setFrameStyle(QFrame::Box | QFrame::Sunken);
    setLineWidth(2);
    setAcceptDrops(true);
}

void Spielfeld::dragEnterEvent(QDragEnterEvent *event)
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

void Spielfeld::dragMoveEvent(QDragMoveEvent *event)
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

void Spielfeld::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        Regeln *pRegeln = new Regeln();

        // Es wird geprüft, liegt hier schon ein Stein und darf hier ein Stein legen
        // Wenn dort kein Stein liegen darf, wird der Stein zurück in die Benutzerhand gelegt
        /************************************************************************************************************************************/

        // prüfen ob allererster Stein
        int i, j;
        if(SteinImFeld == 0)
        {
            for( i = 0; i < 108; i++ )
            {
                for( j = 0; j < 108; j++ )
                {
                    if( feldarray[i][j][1] != 9 )        // Spielstein im Spielfeld bereits drinnen
                       SteinImFeld = 1;
                }
                                qDebug("1.Stein_Schleife");
            }
        }

        if( SteinImFeld == 1 )
        {
                            qDebug("anfang_2.stein schleife");
            // soll ausgeführt werden, wenn er nicht gelegt werden darf
            if ( this->childAt( 10, 10 ) != nullptr || pRegeln->check( spalte, reihe, getFarbePixmap(pixmap) ,getFormPixmap(pixmap) ) == false )
            {
                qDebug("falsch_schleife");
                Game* pframe = new Game();
                QLabel *newIcon = new QLabel( );

                newIcon->setParent( undoClass::undoParent.top() );
                newIcon->setPixmap( pixmap );
                newIcon->move( undoClass::undoCoordOldX.top(), undoClass::undoCoordOldY.top() );
                newIcon->show();
                newIcon->setAttribute(Qt::WA_DeleteOnClose);

                /*****Stack updaten***********************************/
                undoClass::undoParent.pop();
                undoClass::undoCoordOldX.pop();
                undoClass::undoCoordOldY.pop();
                undoClass::undoPixmap.pop();

                /*************************************************************************************************************/
                // Wenn der Stein zuvor auf einem Spielfeld lag, müssen wir das feldarray des alten Sielsteins updaten.
                /*if(  )
                feldarray[ undoClass::undoParent.top()->spalte][reihe][0] = 0;
                feldarray[spalte][reihe][1] = 9;
                feldarray[spalte][reihe][2] = 9;
                feldarray[spalte][reihe][3] = 0;
                feldarray[spalte][reihe][4] = 0;
                */
                pframe->update();                
                return;
            }
        }

        qDebug("Nach den if schleifen");

        // feldarray mit Werten initialisieren
        if ( undoClass::undoStack.empty() == true )
            feldarray[spalte][reihe][0] = 1;
        feldarray[spalte][reihe][1] = getFarbePixmap(pixmap);
        feldarray[spalte][reihe][2] = getFormPixmap(pixmap);
        feldarray[spalte][reihe][3] = 1;

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pixmap);
        newIcon->move( 0, 0 );
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        undoClass::undoStack.push( newIcon );
        undoClass::undoCoordNewX.push( newIcon->x() );
        undoClass::undoCoordNewY.push( newIcon->y() );

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
            qDebug("Drop_Action");
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Spielfeld::mousePressEvent(QMouseEvent *event)
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

    // Feldarray aktualisieren und auf Null stellen
    feldarray[spalte][reihe][0] = 0;
    feldarray[spalte][reihe][1] = 9;
    feldarray[spalte][reihe][2] = 9;
    feldarray[spalte][reihe][3] = 0;
    feldarray[spalte][reihe][4] = 0;

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
