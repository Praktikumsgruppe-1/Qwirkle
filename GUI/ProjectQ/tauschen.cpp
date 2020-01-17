 #include "tauschen.h"
#include "benutzerhand.h"
#include "game.h"
#include "ui_game.h"
#include <QDropEvent>
#include <QMimeData>

Tauschen::Tauschen(QWidget *parent)
{
    setAcceptDrops(true);
}

void Tauschen::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

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

void Tauschen::SteinTauschen()
{
    Game* pframe2 = new Game();
    Benutzerhand* hand = pframe2->getUi()->frame_2;
    //Benutzerhand* hand = undoClass::undoParent.top();

    int r,g;
    r = randInt(0,5);
    g = randInt(0,5);
    Benutzerhand* hand4 = new Benutzerhand(hand, r , g);
    hand4-> setGeometry(undoClass::undoCoordOldX.top(),undoClass::undoCoordOldY.top(),75,75);

    //******Alten Stein loeschen**************************
    undoClass::undoStack.top()->close();
    pframe2->updateFrames();
}
