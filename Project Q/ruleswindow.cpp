/**********************************************************************/
// Datei: ruleswindow.cpp
// Die Klasse rulesWindow enthaelt ein QWidget um ein neues Fenster bei
// Bedarf zu oeffnen, wo die Regeln dargestellt werden.
/**********************************************************************/

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QLabel>

#include "ruleswindow.h"
#include "ui_ruleswindow.h"


// Konstruktor
rulesWindow::rulesWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rulesWindow)
{
    ui->setupUi(this);


    ui->scrollArea->setMinimumSize(20,20);
    ui->scrollArea->setMaximumSize(1600,900);
    ui->scrollAreaWidgetContents->setMaximumSize(4000,4000);

    ui->scrollAreaWidgetContents->setLayout( ui->lregel );
    ui->scrollArea->setWidget( ui->scrollAreaWidgetContents );

}


// Destruktor
rulesWindow::~rulesWindow()
{
    delete ui;
}


// ruft ein Fenster auf, in dem die Regeln abgebildet sind
void rulesWindow::showRules(){
    ui->setupUi(this);
}


// Slot: Schließen des Fensters
void rulesWindow::on_pushButton_clicked()
{
    close();
}

