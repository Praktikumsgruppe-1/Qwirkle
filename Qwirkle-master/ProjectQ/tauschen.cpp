 #include "tauschen.h"
#include "benutzerhand.h"
#include "game.h"
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

// Es wird ein Stein getauscht, indem der fallengelassene Stein gelöscht und ein neuer
// Stein erstellt wird
void Tauschen::SteinTauschen(){
    Game* pframe2 = new Game();
    QLabel *newIcon = new QLabel( );

    newIcon->setParent( undoClass::undoParent.top() );
    newIcon->setPixmap( getPixmap( randInt(0, 5), randInt(0, 5) ) );
    newIcon->move( undoClass::undoCoordOldX.top(), undoClass::undoCoordOldY.top() );
    newIcon->show();
    newIcon->setAttribute(Qt::WA_DeleteOnClose);

    //undoClass::undoStack.top()->close();
    pframe2->updateFrames();
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
