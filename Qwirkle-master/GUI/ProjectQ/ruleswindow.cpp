/**********************************************************************/
// Datei: ruleswindow.cpp
// Die Klasse rulesWindow, beinhaltet die Inhalte für das Widget-Fenster
// rulesWindow, wo die Regeln angezeigt werden.
/**********************************************************************/
#include "ruleswindow.h"
#include "ui_ruleswindow.h"

#include <QGraphicsPixmapItem>
#include <QPixmap>

// Konstruktor
rulesWindow::rulesWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rulesWindow) {
    ui->setupUi(this);
}

// Destruktor
rulesWindow::~rulesWindow() {
    delete ui;
}

// Wenn auf den Button "Beenden" drauf geklickt wird, wird diese Funktion
// aufgerufen, die bewirkt dass das Fenster geschlossen wird.
void rulesWindow::on_pushButton_clicked() {
    close();
}

// ruft ein Fenster auf, in dem die Regeln abgebildet werden
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
