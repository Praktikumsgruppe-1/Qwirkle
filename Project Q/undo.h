/**********************************************************************/
// Datei: undo.h
// Die Klasse undoClass enthalet mehrere Stacks zum Managen der undo
// Funktion sowie eine Funktion die den Zug rueckgaengig macht
/**********************************************************************/
#ifndef UNDO_H
#define UNDO_H

#include <stack>
#include <QLabel>
#include <QFrame>
#include <QUndoCommand>

class undoClass : QFrame
{
    Q_OBJECT
public:
    explicit undoClass( QWidget *parent = nullptr );
    ~undoClass( );

private:
    static std::stack< QLabel* > undoStack;             // Stack mit Zeiger auf den Spielstein, der bewegt wird
    static std::stack< int > undoCoordOldX;             // Stack mit Koordinaten auf die ursprüngliche Position, bevor der Stein bewegt wird
    static std::stack< int > undoCoordOldY;             // Stack mit Koordinaten auf die ursprüngliche Position, bevor der Stein bewegt wird
    static std::stack< QFrame* > undoParent;
    static std::stack< QPixmap > undoPixmap;
    static std::stack< int > undoReihe;
    static std::stack< int > undoSpalte;

    friend class Benutzerhand;
    friend class Spielfeld;
    friend class Tauschen;
    friend class Game;

public slots:
    void undoMove( );                                    // macht eine Bewegung eines Spielsteins rückgängig
};

#endif // UNDOMOVE_H
