#ifndef UNDOMOVE_H
#define UNDOMOVE_H

#include <stack>
#include <QLabel>
#include "benutzerhand.h"
#include "game.h"
#include "spielfeld.h"
#include <QUndoCommand>
#include "tauschen.h"

// Eine Klasse für die Verwaltung/ Funktionalität der Buttons

class undoClass : public Benutzerhand
{
    Q_OBJECT;
public:
    explicit undoClass(QWidget *parent = nullptr);
    ~undoClass();

private:
    static std::stack< QLabel* > undoStack;      // Stack mit Zeiger auf den Spielstein, der bewegt wird
    static std::stack< int > undoCoordOldX;            // Stack mit Koordinaten auf die ursprüngliche Position, bevor der Stein bewegt wird
    static std::stack< int > undoCoordOldY;            // Stack mit Koordinaten auf die ursprüngliche Position, bevor der Stein bewegt wird
    static std::stack< int > undoCoordNewX;            // Stack mit Koordinaten auf die ursprüngliche Position, bevor der Stein bewegt wird
    static std::stack< int > undoCoordNewY;
    static std::stack< QFrame* > undoParent;
    static std::stack< QPixmap > undoPixmap;

    friend class Benutzerhand;
    friend class Spielfeld;
    friend class Tauschen;

public slots:
    void undoMove();                                // macht eine Bewegung eines Spielsteins rückgängig
};

#endif // UNDOMOVE_H
