#include "lobbyerst.h"
#include "ui_lobbyerst.h"
#include "game.h"

LobbyErst::LobbyErst(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LobbyErst)
{
    ui->setupUi(this);
}

LobbyErst::~LobbyErst()
{
    delete ui;
}

void LobbyErst::on_pushButton_clicked()
{
   Game *pgame = new Game;
   pgame->show();

   close();
}
