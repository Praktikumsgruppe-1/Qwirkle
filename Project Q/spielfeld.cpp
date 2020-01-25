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

int SteinImFeld = 0;

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

void Spielfeld::feldArrayZuruecksetzen( )
{
    feldarray[spalte][reihe][0] = 0;
    feldarray[spalte][reihe][1] = 9;
    feldarray[spalte][reihe][2] = 9;
    feldarray[spalte][reihe][3] = 0;
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
                    qDebug("1. stein schleife")
                }
            }
        }
        
        // feldarray mit Werten initialisieren
        if ( undoClass::undoStack.empty() == true )
            feldarray[spalte][reihe][0] = 1;
        feldarray[spalte][reihe][1] = getFarbePixmap(pixmap);
        feldarray[spalte][reihe][2] = getFormPixmap(pixmap);
        feldarray[spalte][reihe][3] = 1;

        // feldarray mit Werten initialisieren
        if ( undoClass::undoStack.empty() == true )
            feldarray[spalte][reihe][0] = 1;
        feldarray[spalte][reihe][1] = getFarbePixmap(pixmap);
        feldarray[spalte][reihe][2] = getFormPixmap(pixmap);
        feldarray[spalte][reihe][3] = 1;

        if( SteinImFeld == 1 )
        {
                            qDebug("anfang_2.stein schleife");
            // soll ausgeführt werden, wenn er nicht gelegt werden darf
            if ( this->childAt( 10, 10 ) != nullptr || pRegeln->check( reihe, spalte, getFarbePixmap(pixmap) ,getFormPixmap(pixmap) ) == false )

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
                undoClass::undoStack.pop();
                undoClass::undoParent.pop();
                undoClass::undoCoordOldX.pop();
                undoClass::undoCoordOldY.pop();
                undoClass::undoPixmap.pop();
                undoClass::undoReihe.pop();
                undoClass::undoSpalte.pop();

                pframe->update();
                qDebug() << "---Stein darf nich abgelegt werden---";
                return;
            }
        }

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pixmap);
        newIcon->move( 0, 0 );
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        undoClass::undoStack.push( newIcon );
        undoClass::undoReihe.push( reihe );
        undoClass::undoSpalte.push( spalte );

        qDebug() << "---Stein wurde erstellt";

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
