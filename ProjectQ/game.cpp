#include "game.h"
#include "ui_game.h"
#include "benutzerhand.h"
#include "spielfeld.h"
#include "ruleswindow.h"
#include <QPixmap>
#include <QFrame>

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);

    //ui->swap = new QFrame(QPixmap("/images/retry.png"))
    //ui->hand
    //ui->frame_2 =  new Benutzerhand(ui->hand,3,4);
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
