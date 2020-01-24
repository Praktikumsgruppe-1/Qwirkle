#include "ruleswindow.h"
#include "ui_ruleswindow.h"

#include <QGraphicsPixmapItem>
#include <QPixmap>

rulesWindow::rulesWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rulesWindow)
{
    ui->setupUi(this);
}

rulesWindow::~rulesWindow()
{
    delete ui;
}

void rulesWindow::on_pushButton_clicked()
{
    close();
}

// ruft ein Fenster auf, in dem die Regeln abgebildet sind
void rulesWindow::showRules(){

    rulesWindow *pRulesWidget = new rulesWindow;

    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsView *graphicsView = new QGraphicsView();

    QGraphicsPixmapItem *pixmapItem1 = scene->addPixmap(QPixmap(":/rulesImages/Spielanleitung_Qwirkle_1.PNG"));
    QGraphicsPixmapItem *pixmapItem2 = scene->addPixmap(QPixmap(":/rulesImages/Spielanleitung_Qwirkle_2.PNG"));
    QGraphicsPixmapItem *pixmapItem3 = scene->addPixmap(QPixmap(":/rulesImages/Spielanleitung_Qwirkle_3.PNG"));

    pixmapItem2->moveBy(0, 795);
    pixmapItem3->moveBy(0, 1590);

    pRulesWidget->ui->graphicsView->setScene(scene);

    pRulesWidget->show();
}
