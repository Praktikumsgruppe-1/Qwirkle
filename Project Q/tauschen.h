/**********************************************************************/
// Datei: tauschen.h
// Die Klasse Tauschen enthaelt eine Funktion zum Tauschen und die
// Moeglichkeit des droppens auf dem Tauschen Feld
/**********************************************************************/
#ifndef TAUSCHEN_H
#define TAUSCHEN_H

#include <QFrame>

class Game;

class Tauschen : public QFrame
{
public:
    explicit Tauschen( QWidget *parent = nullptr );
    void SteinTauschen( );

    static std::vector< QFrame* >getauschteSteine;

protected:
    void dragEnterEvent( QDragEnterEvent *event ) override;
    void dropEvent( QDropEvent *event ) override;
};



#endif // TAUSCHEN_H
