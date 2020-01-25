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

    int a = 0, b = 0, c = 0;
    {                                               // neuen Stein generieren, der noch im Beutel ist
        a = randInt( 0, 5 );
        b = randInt( 0, 5);
        c = randInt( 0, 2 );
    } while ( beutel[a][b][c] == false );
    beutel[a][b][c] = false;

    newIcon->setParent( undoClass::undoParent.top() );
    newIcon->setPixmap( getPixmap( a, b ));
    newIcon->move( undoClass::undoCoordOldX.top(), undoClass::undoCoordOldY.top() );
    newIcon->show();
    newIcon->setAttribute(Qt::WA_DeleteOnClose);

    //pgame->updateFrames();

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

/**************************************************************************************************************************************/
        SteinTauschen();           // wie könnten wir hier ein Game* übergeben????

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
