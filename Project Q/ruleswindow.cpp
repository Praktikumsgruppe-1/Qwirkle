#include "ruleswindow.h"
#include "ui_ruleswindow.h"

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QLabel>

rulesWindow::rulesWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rulesWindow)
{
    ui->setupUi(this);


    ui->scrollArea->setMinimumSize(20,20);
    ui->scrollArea->setMaximumSize(1600,900);
    ui->scrollAreaWidgetContents->setMaximumSize(4000,4000);

    /*
    QFrame item1;
    item1.setPixmap(QPixmap(":/rulesImages/Spielanleitung_Qwirkle_1.PNG"));
    QLabel item2;
    item2.setPixmap(QPixmap(":/rulesImages/Spielanleitung_Qwirkle_2.PNG"));
    QLabel item3;
    item3.setPixmap(QPixmap(":/rulesImages/Spielanleitung_Qwirkle_1.PNG"));

    ui->lregel->addWidget(item1);
    ui->lregel->addWidget(item2);
    ui->lregel->addWidget(item3);
    */

    ui->scrollAreaWidgetContents->setLayout( ui->lregel );
    ui->scrollArea->setWidget( ui->scrollAreaWidgetContents );

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

    /*
    rulesWindow *pRulesWidget = new rulesWindow;

    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsView graphicsView (scene);

    QGraphicsPixmapItem *pixmapItem1 = scene->addPixmap(QPixmap(":/rulesImages/Spielanleitung_Qwirkle_1.PNG"));
    QGraphicsPixmapItem *pixmapItem2 = scene->addPixmap(QPixmap(":/rulesImages/Spielanleitung_Qwirkle_2.PNG"));
    QGraphicsPixmapItem *pixmapItem3 = scene->addPixmap(QPixmap(":/rulesImages/Spielanleitung_Qwirkle_3.PNG"));

    pixmapItem1->moveBy(0,    1);
    pixmapItem2->moveBy(0,  796);
    pixmapItem3->moveBy(0, 1591);

    pRulesWidget->ui->graphicsView->setScene(scene);

    pRulesWidget->show();
    */

    ui->setupUi(this);
}
