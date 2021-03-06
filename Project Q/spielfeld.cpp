/**********************************************************************/
// Datei: spielfeld.h
// Die Klasse Spielfeld enthaelt ein QFrame, mit dem die einzelnen Felder
// auf dem Spielfeld erstellt werden, die mit Drop Funktion ausgestattet
// sind.))
/**********************************************************************/

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

#include "spielfeld.h"
#include "undo.h"
#include "regeln.h"
#include "benutzerhand.h"
#include "game.h"
#include "tauschen.h"


// static Variable initialisieren
int SteinImFeld = 0;
int allerersterStein = 0;


// Konstruktor
Spielfeld::Spielfeld(QWidget *parent, int spalteX, int reiheY )
    : QFrame(parent), reihe( reiheY ), spalte( spalteX )
{
    setMinimumSize(75, 75);
    setMaximumSize(200,200);
    setFrameStyle(QFrame::Box | QFrame::Sunken);
    setLineWidth(2);
    setAcceptDrops(true);
}


// setzt das feldArray, welches in game.h als extern definiert wurde, auf Werte
// die als nicht definiert gelten sollen
void Spielfeld::feldArrayZuruecksetzen( )
{
    feldarray[reihe][spalte][0] = 0;
    feldarray[reihe][spalte][1] = 9;
    feldarray[reihe][spalte][2] = 9;
    feldarray[reihe][spalte][3] = 0;
}


/***************** Drop Funktionen ********************************************/

// dragEnterEvent
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


// dropEvent, welches den Stein in das Spielfeld setzt und einige Werte zuordnet
void Spielfeld::dropEvent(QDropEvent *event)
{
   qDebug() << "Drop Event beginnt";
   qDebug() << "allerersterStein?" << allerersterStein;
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        Regeln *pRegeln = new Regeln();

        /******************************************************************************/
        // Es wird geprüft, liegt hier schon ein Stein und darf hier ein Stein legen

        qDebug()<<"für den allerersten Stein sollte das 0 sein:" << allerersterStein;
        qDebug()<<"nach dem ersten stein sollte das 1 sein:" << SteinImFeld;
        // feldarray mit Werten initialisieren

         if ( allerersterStein == 0 )
         {
             feldarray[reihe][spalte][0] = 1;
             feldarray[reihe][spalte][1] = getFarbePixmap(pixmap);
             feldarray[reihe][spalte][2] = getFormPixmap(pixmap);
             feldarray[reihe][spalte][3] = 1;
         }

         if ( undoClass::undoStack.empty() == true )     // wenn noch kein Stein auf das SPielfeld gelegt wurde,
        {                                               // wird der gedroppte Stein als erstgelegter Stein markiert 
            feldarray[reihe][spalte][0] = 1;
            qDebug() << "test++++++++++++++";
        }

        if( SteinImFeld == 0 && allerersterStein != 0)                          // verhindern, dass die check Funktion von Regeln ausgeführt wird,
        {                                               // wenn noch keit Stein im Feld liegt
            qDebug("anfang_1.stein schleife");
            qDebug() << "Feldarray vor dem Check1: " << feldarray[reihe][spalte][0]<< feldarray[reihe][spalte][1] << feldarray[reihe][spalte][2] << feldarray[reihe][spalte][3] << "Koordinaten:"<< reihe << spalte;
            // soll ausgeführt werden, wenn er nicht gelegt werden darf oder bereits ein Stein drinnen liegt
            if ( this->childAt( 10, 10 ) != nullptr || pRegeln->check1( reihe, spalte, getFarbePixmap(pixmap) ,getFormPixmap(pixmap) ) == false )
            {
                qDebug("falsch_schleife");
                qDebug() << "Daten der falsch_Schleife" << reihe << spalte << getFarbePixmap(pixmap) << getFormPixmap(pixmap);
                /*** neuen Stein erstellen, der dargestellt wird in der Benutzerhand ***/

                //Game* pframe = new Game();

                /*
                QLabel *newIcon = new QLabel( );
                newIcon->setParent( undoClass::undoParent.top() );
                newIcon->setPixmap( pixmap );
                newIcon->move( undoClass::undoCoordOldX.top(), undoClass::undoCoordOldY.top() );
                newIcon->show();
                newIcon->setAttribute(Qt::WA_DeleteOnClose);
                */

                /***** Undo Stack updaten ***************************************/
                undoClass::undoParent.pop();
                undoClass::undoCoordOldX.pop();
                undoClass::undoCoordOldY.pop();
                undoClass::undoPixmap.pop();

                feldarray[reihe][spalte][0] = 0;
                feldarray[reihe][spalte][1] = 9;
                feldarray[reihe][spalte][2] = 9;
                feldarray[reihe][spalte][3] = 0;

                qDebug() << "feldarray nach falsch: " << feldarray[reihe][spalte][0] << feldarray[reihe][spalte][1] << feldarray[reihe][spalte][2] << feldarray[reihe][spalte][3];

                //Game::frosch->update();
                qDebug() << "---Stein darf nicht abgelegt werden---" << "undo Stack size:" << undoClass::undoStack.size() ;
                return;
            }
        }

        if( SteinImFeld > 0 )                          // verhindern, dass die check Funktion von Regeln ausgeführt wird,
        {                                               // wenn noch keit Stein im Feld liegt
            qDebug("anfang_2.stein schleife");
            qDebug() << "Feldarray vor dem Check2: " << feldarray[reihe][spalte][0]<< feldarray[reihe][spalte][1] << feldarray[reihe][spalte][2] << feldarray[reihe][spalte][3] << "Koordinaten:"<< reihe << spalte;
            // soll ausgeführt werden, wenn er nicht gelegt werden darf oder bereits ein Stein drinnen liegt
            if ( this->childAt( 10, 10 ) != nullptr || pRegeln->check2( reihe, spalte, getFarbePixmap(pixmap) ,getFormPixmap(pixmap) ) == false )
            {
                qDebug("falsch_schleife");
                qDebug() << "Daten der falsch_Schleife" << reihe << spalte << getFarbePixmap(pixmap) << getFormPixmap(pixmap);
                /*** neuen Stein erstellen, der dargestellt wird in der Benutzerhand ***/
                //Game* pframe = new Game();
                /*QLabel *newIcon = new QLabel( );

                newIcon->setParent( undoClass::undoParent.top() );
                newIcon->setPixmap( pixmap );
                newIcon->move( undoClass::undoCoordOldX.top(), undoClass::undoCoordOldY.top() );
                newIcon->show();
                newIcon->setAttribute(Qt::WA_DeleteOnClose);*/
                
                /***** Undo Stack updaten ***************************************/
                undoClass::undoParent.pop();
                undoClass::undoCoordOldX.pop();
                undoClass::undoCoordOldY.pop();
                undoClass::undoPixmap.pop();

                if( this->childAt( 10, 10 ) == nullptr )
                {
                    feldarray[reihe][spalte][0] = 0;
                    feldarray[reihe][spalte][1] = 9;
                    feldarray[reihe][spalte][2] = 9;
                    feldarray[reihe][spalte][3] = 0;
                }


                Game::frosch->update();
                qDebug() << "---Stein darf nicht abgelegt werden---" << "undo Stack size:" << undoClass::undoStack.size() ;
                return;
            }
        }

        feldarray[reihe][spalte][1] = getFarbePixmap(pixmap);
        feldarray[reihe][spalte][2] = getFormPixmap(pixmap);
        feldarray[reihe][spalte][3] = 1;


        /********************************************************************************/
        // Wenn dort kein Stein liegen darf, wird der Stein zurück in die Benutzerhand gelegt

        /**** neuen Stein erstellen, der in dem Spielfeld dargestellt wird **************/

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pixmap);
        newIcon->move( 0, 0 );
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        undoClass::undoStack.push( newIcon );               // Werte in den undoStack tun
        undoClass::undoReihe.push( reihe );
        undoClass::undoSpalte.push( spalte );
        qDebug() << this;
        qDebug() << "---Stein wurde erstellt";

        SteinImFeld++;
        allerersterStein = 1;
        qDebug() << "erster stein im zug:" << feldarray[reihe][spalte][0] << "Farbe:" << feldarray[reihe][spalte][1] << "Form:" << feldarray[reihe][spalte][2] << "neu gelegt:" << feldarray[reihe][spalte][3] << "Koordinaten:" << reihe << spalte;
        qDebug() << "feldarray des ersten Feldes:" << feldarray[0][0][0] << feldarray[0][0][1] << feldarray[0][0][2] << feldarray[0][0][3];

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
