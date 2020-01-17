#ifndef GAME_H
#define GAME_H

#include <QWidget>
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

    void updateFrames();
    QWidget* findChildAt( int x, int y, QObject* frameVar );
    Ui::Game* getUi();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_undoButton_clicked();

    void on_pushButton_6_clicked();

    void on_widget_3_windowIconChanged(const QIcon &icon);

private:
    Ui::Game *ui;

    friend class undoClass;
    friend class Tauschen;
};

#endif // GAME_H
