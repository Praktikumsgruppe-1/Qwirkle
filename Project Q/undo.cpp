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
        //Game* pframe = new Game();
        QLabel *newIcon = new QLabel( );

        newIcon->setParent( undoClass::undoParent.top() );
        newIcon->setPixmap( *(undoClass::undoStack.top()->pixmap()) );
        newIcon->move( undoClass::undoCoordOldX.top(), undoClass::undoCoordOldY.top() );
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        //******Alten Stein loeschen**************************
        undoClass::undoStack.top()->close();
        //pframe->updateFrames();

        /*****feldarray aktualisieren****************************/
        feldarray[ undoClass::undoSpalte.top() ][ undoClass::undoReihe.top() ][ 0 ] = 0;
        feldarray[ undoClass::undoSpalte.top() ][ undoClass::undoReihe.top() ][ 1 ] = 9;
        feldarray[ undoClass::undoSpalte.top() ][ undoClass::undoReihe.top() ][ 2 ] = 9;
        feldarray[ undoClass::undoSpalte.top() ][ undoClass::undoReihe.top() ][ 3 ] = 0;
        feldarray[ undoClass::undoSpalte.top() ][ undoClass::undoReihe.top() ][ 4 ] = 0;

        /*****Stack updaten***********************************/
        undoClass::undoStack.pop();
        undoClass::undoParent.pop();
        undoClass::undoCoordOldX.pop();
        undoClass::undoCoordOldY.pop();
        undoClass::undoPixmap.pop();
        undoClass::undoReihe.pop();
        undoClass::undoSpalte.pop();
    }
    return;
}

std::stack<QLabel*> undoClass::undoStack;
std::stack< int > undoClass::undoCoordOldX;
std::stack< int > undoClass::undoCoordOldY;
std::stack< QFrame* > undoClass::undoParent;
std::stack< QPixmap > undoClass::undoPixmap;
std::stack< int > undoClass::undoReihe;
std::stack< int > undoClass::undoSpalte;
