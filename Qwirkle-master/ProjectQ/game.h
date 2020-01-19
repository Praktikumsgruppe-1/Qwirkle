#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QScrollArea>
#include "tauschen.h"
#include "undo.h"

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

    Ui::Game* getUi();
    // aktualisiert alle Frames in dem ui des Games
    void updateFrames();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Game *ui;
};

#endif // GAME_H
