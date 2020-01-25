#include "tauschen.h"
#include "benutzerhand.h"
#include "game.h"
#include "undo.h"

#include "ui_game.h"
#include <QDropEvent>
#include <QMimeData>
#include <QDrag>
#include <QPainter>

// Konstruktor der Klasse Tauschen
Tauschen::Tauschen(QWidget *parent)
    : QFrame(parent)
{
    setAcceptDrops(true);
}

// Es wird ein Stein getauscht, indem der fallengelassene Stein gelöscht und ein neuer
// Stein erstellt wird
void Tauschen::SteinTauschen(){
    QLabel *newIcon = new QLabel( );

    int atest = Game::beutelStackFarbe.back();
    int btest = Game::beutelStackForm.back();

    newIcon->setParent( undoClass::undoParent.top() );
    newIcon->setPixmap( getPixmap( atest, btest ));
    newIcon->move( undoClass::undoCoordOldX.top(), undoClass::undoCoordOldY.top() );
    newIcon->show();
    newIcon->setAttribute(Qt::WA_DeleteOnClose);

    //pgame->updateFrames();

    Game::beutelStackForm.pop_back();
    Game::beutelStackFarbe.pop_back();
    Game::beutelStackKopie.pop_back();

    int form = getFormPixmap( undoClass::undoPixmap.top() );
    int farbe = getFarbePixmap( undoClass::undoPixmap.top() );

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

    Game::beutelMischen();

    undoClass::undoParent.pop();
    undoClass::undoCoordOldX.pop();
    undoClass::undoCoordOldY.pop();
    undoClass::undoPixmap.pop();
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
