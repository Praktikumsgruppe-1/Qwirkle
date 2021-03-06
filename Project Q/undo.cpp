/**********************************************************************/
// Datei: undo.cpp
// Die Klasse undoClass enthalet mehrere Stacks zum Managen der undo
// Funktion sowie eine Funktion die den Zug rueckgaengig macht
/**********************************************************************/

#include <QLabel>
#include <QFrame>
#include <QTextStream>
#include <QDebug>

#include "undo.h"
#include "ui_game.h"
#include "benutzerhand.h"
#include "game.h"
#include "spielfeld.h"
#include "tauschen.h"


// static Variablen initialisieren
std::stack<QLabel*> undoClass::undoStack;
std::stack< int > undoClass::undoCoordOldX;
std::stack< int > undoClass::undoCoordOldY;
std::stack< QFrame* > undoClass::undoParent;
std::stack< QPixmap > undoClass::undoPixmap;
std::stack< int > undoClass::undoReihe;
std::stack< int > undoClass::undoSpalte;


// Konstruktor
undoClass::undoClass( QWidget *parent )
{

}


// Destruktor
undoClass::~undoClass()
{

}


// macht eine Bewegung eines Spielsteins rückgängig, indem der letzte bewegte Spielstein
// vom Spielfeld gelöscht wird und auf die Benutzerhand gelegt wird.
void undoClass::undoMove()
{
    if ( !undoClass::undoStack.empty() )
    {
        qDebug("*******Neuen Stein erstellen und platzieren**********");

        /*** neuer Stein wird erstellt mit alten Werten ********/
        QLabel *newIcon = new QLabel( );
        newIcon->setParent( undoClass::undoParent.top() );
        newIcon->setPixmap( *(undoClass::undoStack.top()->pixmap()) );
        newIcon->move( undoClass::undoCoordOldX.top(), undoClass::undoCoordOldY.top() );
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        /******Alten Stein loeschen***************************/
        undoClass::undoStack.top()->close();

        /*****feldarray aktualisieren****************************/
        feldarray[ undoClass::undoReihe.top() ][ undoSpalte.top() ][ 0 ] = 0;
        feldarray[ undoClass::undoReihe.top() ][ undoSpalte.top() ][ 1 ] = 9;
        feldarray[ undoClass::undoReihe.top() ][ undoSpalte.top() ][ 2 ] = 9;
        feldarray[ undoClass::undoReihe.top() ][ undoSpalte.top() ][ 3 ] = 0;
        feldarray[ undoClass::undoReihe.top() ][ undoSpalte.top() ][ 4 ] = 0;
        qDebug()<< "nach dem undo: " << feldarray[ undoClass::undoSpalte.top() ][ undoClass::undoReihe.top() ][ 0 ] << feldarray[ undoClass::undoSpalte.top() ][ undoClass::undoReihe.top() ][ 1 ] <<feldarray[ undoClass::undoSpalte.top() ][ undoClass::undoReihe.top() ][ 2 ] << feldarray[ undoClass::undoSpalte.top() ][ undoClass::undoReihe.top() ][ 4 ] << undoClass::undoSpalte.top() << undoClass::undoReihe.top() ;

        /*****Stack updaten***********************************/
        undoClass::undoStack.pop();
        undoClass::undoParent.pop();
        undoClass::undoCoordOldX.pop();
        undoClass::undoCoordOldY.pop();
        undoClass::undoPixmap.pop();
        undoClass::undoReihe.pop();
        undoClass::undoSpalte.pop();

        /*** Variable aktualisieren, wenn der erstplatzierte Stein rueckgaengig gemacht wird ***/
        SteinImFeld--;

        if( allerersterStein == 1 )
            allerersterStein = 0;
    }
    return;
}
