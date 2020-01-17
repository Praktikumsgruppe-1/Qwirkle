#include "game.h"
#include "ui_game.h"
#include "benutzerhand.h"
#include "spielfeld.h"
#include "ruleswindow.h"
#include "einstellungen.h"
#include "tauschen.h"
#include <QDebug>

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);

    ui->frame_3 = new QFrame();

    Benutzerhand* hand = Game::ui->frame_2;
    int r,g;

    r = randInt(0,5);
    g = randInt(0,5);

    Benutzerhand* hand1 = new Benutzerhand(hand, r, g);
    hand1-> setGeometry(1,1,75,75);

    r = randInt(0,5);
    g = randInt(0,5);

    Benutzerhand* hand2 = new Benutzerhand(hand, r, g);
    hand2-> setGeometry(80,1,75,75);

    r = randInt(0,5);
    g = randInt(0,5);

    Benutzerhand* hand3 = new Benutzerhand(hand, r, g);
    hand3-> setGeometry(159,1,75,75);

    r = randInt(0,5);
    g = randInt(0,5);

    Benutzerhand* hand4 = new Benutzerhand(hand, r , g);
    hand4-> setGeometry(238,1,75,75);

    r = randInt(0,5);
    g = randInt(0,5);

    Benutzerhand* hand5 = new Benutzerhand(hand, r, g);
    hand5-> setGeometry(317,1,75,75);

    r = randInt(0,5);
    g = randInt(0,5);

    Benutzerhand* hand6 = new Benutzerhand(hand, r, g);
    hand6-> setGeometry(396,1,75,75);
}

Game::~Game()
{
    delete ui;
}

void Game::on_pushButton_clicked()
{
    close();
}

void Game::on_pushButton_2_clicked()
{
    rulesWindow *pRules = new rulesWindow;
    pRules->showRules();

}

void Game::on_pushButton_3_clicked()
{
    Einstellungen *pEinst = new Einstellungen;
    pEinst->show();
}

void Game::on_undoButton_clicked()
{
    undoClass uC;
    uC.undoMove();
}

// aktualisiert alle Frames in dem ui des Games
void Game::updateFrames()
{
    ui->frame->update();
    ui->frame_2->update();
}

QWidget* Game::findChildAt( int x, int y, QObject* frameVar )
{
    //return static_cast<QWidget*>( Game::ui->frame->children().last() );
    if ( frameVar == (Game::ui->frame) )
    {
        qDebug() << "frame------------";
        return Game::ui->frame->childAt( x, y );
    }
    else
    {
        qDebug() << "frame2------------";
        return Game::ui->frame_2->childAt( x, y );
    }
}

Ui::Game* Game::getUi()
{
    return Game::ui;
}
