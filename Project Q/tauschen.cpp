/**********************************************************************/
// Datei: tauschen.cpp
// Die Klasse Tauschen enthaelt eine Funktion zum Tauschen und die
// Moeglichkeit des droppens auf dem Tauschen Feld
/**********************************************************************/

#include "ui_game.h"
#include <QDropEvent>
#include <QMimeData>
#include <QDrag>
#include <QPainter>
#include <QHBoxLayout>

#include "tauschen.h"
#include "benutzerhand.h"
#include "game.h"
#include "undo.h"


// static Variable initialisieren
std::vector< QFrame* >Tauschen::getauschteSteine;


// Konstruktor
Tauschen::Tauschen(QWidget *parent)
    : QFrame(parent)
{
    setAcceptDrops(true);
}


// Es wird ein Stein getauscht, indem der fallengelassene Stein gelöscht und ein neuer
// Stein erstellt wird
void Tauschen::SteinTauschen(){

    //es wird geprueft ob der zu tauschende Stein von einem Feld stammt wo schon mal getauscht wurde
    bool istGleich = false;                     // ist false, solange wie er noch nicht getauscht wurde
    for( int x = 0; x < 6 && !Tauschen::getauschteSteine.empty() ; x++ )
    {
        if ( Tauschen::getauschteSteine[ x ] == undoClass::undoParent.top() )
        {
            istGleich = true;
            //qDebug() << "Stein Tauschen --------" << Tauschen::getauschteSteine[ x ] << undoClass::undoCoordOldY.top();
        }

    }

    // wenn der Stein von einem Feld stammt, wo noch nicht getauscht wurde wird folgendes ausgefuehrt:
    // bzw. (Tauschen ist erlaubt)
    if( istGleich == false && !Game::beutelStackForm.empty() )
    {
        /*** erstelle ein neuen Stein auf der Benutzerhand aus dem Beutel ***/
        QLabel *newIcon = new QLabel( );
        newIcon->setParent( undoClass::undoParent.top() );
        newIcon->setPixmap( getPixmap( Game::beutelStackFarbe.back(), Game::beutelStackForm.back() ));
        newIcon->move( undoClass::undoCoordOldX.top(), undoClass::undoCoordOldY.top() );
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        /******* Beutel um einen Stein erleichtern *****************************/
        Game::beutelStackForm.pop_back();
        Game::beutelStackFarbe.pop_back();
        Game::beutelStackKopie.pop_back();

        /******* alten Stein in Beutel pushen **********************************/
        int farbe = getFormPixmap( undoClass::undoPixmap.top() );
        int form = getFarbePixmap( undoClass::undoPixmap.top() );

        Game::beutelStackForm.push_back( form );
        Game::beutelStackFarbe.push_back( farbe );

        // freie Kopie herausfinden
        for( int i = 0; i < 108; i++ )
        {
            if( Game::beutelStackForm[ i ] == form && Game::beutelStackFarbe[ i ] == farbe )
            {
                if( Game::beutelStackKopie[ i ] != 0 )
                    Game::beutelStackKopie.push_back( 0 );
                else if( Game::beutelStackKopie[ i ] != 1 )
                    Game::beutelStackKopie.push_back( 1 );
                else
                    Game::beutelStackKopie.push_back( 2 );
            }
        }

        /****** Updates ************************************************/
        Game::beutelMischen();

        Tauschen::getauschteSteine.push_back( undoClass::undoParent.top() );

        undoClass::undoParent.pop();
        undoClass::undoCoordOldX.pop();
        undoClass::undoCoordOldY.pop();
        undoClass::undoPixmap.pop();
    }
    else            // Tauschen ist nicht erlaubt
    {
        /****** Error Fenster anzeigen **********************************/
        QWidget *errorFenster = new QWidget();
        QLabel *labelFenster = new QLabel();
        QHBoxLayout *layoutFenster = new QHBoxLayout();

        errorFenster->setMinimumSize( 500, 100 );
        labelFenster->setText("Error. Du hast den Stein schonmal getauscht.");
        layoutFenster->addWidget( labelFenster );
        errorFenster->setLayout( layoutFenster );

        errorFenster->show();

        /****** Stein wieder auf Benutzehand legen ************************/
        QLabel *newIcon = new QLabel( );
        newIcon->setParent( undoClass::undoParent.top() );
        newIcon->setPixmap( undoClass::undoPixmap.top() );
        newIcon->move( undoClass::undoCoordOldX.top(), undoClass::undoCoordOldY.top() );
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        /****** Updates ************************************************/
        undoClass::undoParent.pop();
        undoClass::undoCoordOldX.pop();
        undoClass::undoCoordOldY.pop();
        undoClass::undoPixmap.pop();

    }
}


// Das DragEnterEvent der Klasse Tauschen
void Tauschen::dragEnterEvent(QDragEnterEvent *event){
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


// Das Drop Event der Klasse Tauschen
void Tauschen::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        SteinTauschen();

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
