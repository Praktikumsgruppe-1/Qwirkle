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

    /*
    Spielfeld *feld01 = new Spielfeld(ui->feld);
    Spielfeld *feld02 = new Spielfeld(ui->feld);
    Spielfeld *feld03 = new Spielfeld(ui->feld);
    Spielfeld *feld04 = new Spielfeld(ui->feld);
    Spielfeld *feld05 = new Spielfeld(ui->feld);
    Spielfeld *feld06 = new Spielfeld(ui->feld);
    Spielfeld *feld07 = new Spielfeld(ui->feld);
    Spielfeld *feld08 = new Spielfeld(ui->feld);
    Spielfeld *feld09 = new Spielfeld(ui->feld);
    Spielfeld *feld10 = new Spielfeld(ui->feld);
    Spielfeld *feld11 = new Spielfeld(ui->feld);
    Spielfeld *feld12 = new Spielfeld(ui->feld);
    Spielfeld *feld13 = new Spielfeld(ui->feld);
    Spielfeld *feld14 = new Spielfeld(ui->feld);
    Spielfeld *feld15 = new Spielfeld(ui->feld);
    Spielfeld *feld16 = new Spielfeld(ui->feld);
    Spielfeld *feld17 = new Spielfeld(ui->feld);
    Spielfeld *feld18 = new Spielfeld(ui->feld);


    ui->lfeld2->addWidget(feld01);
    ui->lfeld2->addWidget(feld02);
    ui->lfeld2->addWidget(feld03);
    ui->lfeld2->addWidget(feld04);
    ui->lfeld2->addWidget(feld05);
    ui->lfeld2->addWidget(feld06);
    ui->lfeld2->addWidget(feld07);
    ui->lfeld2->addWidget(feld08);
    ui->lfeld2->addWidget(feld09);
    ui->lfeld2->addWidget(feld10);
    ui->lfeld2->addWidget(feld11);
    ui->lfeld2->addWidget(feld12);
    ui->lfeld2->addWidget(feld13);
    ui->lfeld2->addWidget(feld14);
    ui->lfeld2->addWidget(feld15);
    ui->lfeld2->addWidget(feld16);
    ui->lfeld2->addWidget(feld17);
    ui->lfeld2->addWidget(feld18);
    */

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
