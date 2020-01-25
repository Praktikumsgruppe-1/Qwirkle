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

    newIcon->setParent( undoClass::undoParent.top() );
    newIcon->setPixmap( getPixmap( Game::beutelStackFarbe.back(), Game::beutelStackForm.back() ));
    newIcon->move( undoClass::undoCoordOldX.top(), undoClass::undoCoordOldY.top() );
    newIcon->show();
    newIcon->setAttribute(Qt::WA_DeleteOnClose);

    //pgame->updateFrames();

    Game::beutelStackForm.pop_back();
    Game::beutelStackFarbe.pop_back();
    Game::beutelStackKopie.pop_back();

    /*********muss noch überarbeitet werden mit QPixmap Vergleich********************/
    /*Game::beutelStackForm.push_back(  );
    Game::beutelStackFarbe.push_back(  );
    Game::beutelStackKopie.push_back(  );
    */

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
