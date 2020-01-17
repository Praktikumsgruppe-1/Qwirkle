#include "game.h"
#include "ui_game.h"
#include "benutzerhand.h"
#include "spielfeld.h"
#include "ruleswindow.h"
#include <QPixmap>
#include <QFrame>
#include <QHBoxLayout>

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);

    /*
    QWidget *hand = new QWidget;
    ui->lhand = new QHBoxLayout(hand);
    //ui->hand
    ui->frame_2 =  new Benutzerhand(hand,3,4);
    ui->lhand->addWidget(ui->frame_2);
    */

    Benutzerhand *icon1 = new Benutzerhand(ui->hand,3,4);
    Benutzerhand *icon2 = new Benutzerhand(ui->hand,1,4);
    Benutzerhand *icon3 = new Benutzerhand(ui->hand,3,5);
    Benutzerhand *icon4 = new Benutzerhand(ui->hand,2,1);
    Benutzerhand *icon5 = new Benutzerhand(ui->hand,5,4);
    Benutzerhand *icon6 = new Benutzerhand(ui->hand,3,4);

    ui->lhand->addWidget(icon1);
    ui->lhand->addWidget(icon2);
    ui->lhand->addWidget(icon3);
    ui->lhand->addWidget(icon4);
    ui->lhand->addWidget(icon5);
    ui->lhand->addWidget(icon6);

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
    pRules->show();

}

// aktualisiert alle Frames in dem ui des Games
void Game::updateFrames()
{
    ui->frame->update();
    ui->hand->update();
}

Ui::Game* Game::getUi()
{
    return Game::ui;
}

void Game::on_pushButton_6_clicked()
{
    undoClass uC;
    uC.undoMove();
}
