#ifndef UNDO_H
#define UNDO_H

#include <stack>
#include <QLabel>
#include <QFrame>
#include <QUndoCommand>

//class Benutzerhand : QFrame{};
// Eine Klasse für die Verwaltung/ Funktionalität der Buttons

class undoClass : QFrame
{
    Q_OBJECT
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
    friend class Game;

public slots:
    void undoMove();                                // macht eine Bewegung eines Spielsteins rückgängig
};

#endif // UNDOMOVE_H
