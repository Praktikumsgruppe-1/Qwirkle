#include "undo.h"
#include "ui_game.h"
#include "benutzerhand.h"
#include "game.h"
#include "spielfeld.h"
#include "tauschen.h"

#include <QLabel>
#include <QFrame>
#include <QTextStream>
#include <QDebug>

// Konstruktor
undoClass::undoClass( QWidget *parent ){

}

// Destruktor
undoClass::~undoClass(){

}

// macht eine Bewegung eines Spielsteins rückgängig, indem der letzte bewegte Spielstein
// vom Spielfeld gelöscht wird und auf die Benutzerhand gelegt wird.
void undoClass::undoMove(){

    if ( !undoClass::undoStack.empty() ) {

        //*******Neuen Stein erstellen und platzieren**********
        Game* pframe = new Game();
        QLabel *newIcon = new QLabel( );

        newIcon->setParent( undoClass::undoParent.top() );
        newIcon->setPixmap( *(undoClass::undoStack.top()->pixmap()) );
        //newIcon->setPixmap( (undoClass::undoPixmap.top()) );
        newIcon->move( undoClass::undoCoordOldX.top(), undoClass::undoCoordOldY.top() );
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        //******Alten Stein loeschen**************************
        undoClass::undoStack.top()->close();
        pframe->updateFrames();

        /*****Stack updaten***********************************/
        undoClass::undoStack.pop();
        undoClass::undoParent.pop();
        undoClass::undoCoordOldX.pop();
        undoClass::undoCoordOldY.pop();
        undoClass::undoCoordNewX.pop();
        undoClass::undoCoordNewY.pop();
        undoClass::undoPixmap.pop();

    }
    return;
}

std::stack<QLabel*> undoClass::undoStack;
std::stack< int > undoClass::undoCoordOldX;
std::stack< int > undoClass::undoCoordOldY;
std::stack< int > undoClass::undoCoordNewX;
std::stack< int > undoClass::undoCoordNewY;
std::stack< QFrame* > undoClass::undoParent;
std::stack< QPixmap > undoClass::undoPixmap;
