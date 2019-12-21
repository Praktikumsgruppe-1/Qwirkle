#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lobbyerst.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    LobbyErst *plobby = new LobbyErst;
    plobby->show();

    close();
}
