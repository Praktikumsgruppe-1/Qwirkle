/**********************************************************************/
// Datei: Einstellungen.cpp
// Die Klasse Einstellungen, beinhaltet die Inhalte für das Widget-Fenster
// Einstellungen, wo später noch Einstelungsmöglichkeiten hinkommen.
/**********************************************************************/
#include "einstellungen.h"
#include  <QLabel>
#include <QHBoxLayout>

// Konstruktor der Klasse Einstellungen
Einstellungen::Einstellungen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Einstellungen) {
    ui->setupUi(this);
}

// Destruktor der Klasse Einstellungen
Einstellungen::~Einstellungen() {
    delete ui;
}

// Wenn auf den Button "About" drauf geklickt wird, wird diese Funktion
// aufgerufen, die bewirkt dass der bisherige Inhalt des Widgets widget
// gelöscht wird und ein Text mit den Credits erscheint.
void Einstellungen::on_pushButton_2_clicked() {
    QLabel *label = new QLabel();
    QHBoxLayout *layout = new QHBoxLayout();

    label->setText("Diese Anwendung ist eine Implementierung von Qwirkle. Credits: ...");
    layout->addWidget(label);
    qDeleteAll(ui->widget->children());

    Einstellungen::ui->widget->setLayout(layout);
    Einstellungen::ui->widget->update();
}

// Wenn auf den Button "Einstellungen" drauf geklickt wird, wird diese Funktion
// aufgerufen, die bewirkt dass der bisherige Inhalt des Widgets widget
// gelöscht wird und ein Text erscheint. Hier werden später möglicherweise
// noch Einstellungsmöglichkeiten hinzugefügt.
void Einstellungen::on_pushButton_clicked() {
    QLabel *label = new QLabel();
    QHBoxLayout *layout = new QHBoxLayout();

    label->setText("Hier kommen Einstellungen hin.");
    layout->addWidget(label);
    qDeleteAll(ui->widget->children());

    Einstellungen::ui->widget->setLayout(layout);
    Einstellungen::ui->widget->update();
}

// Wenn auf den Button "Beenden" drauf geklickt wird, wird diese Funktion
// aufgerufen, die bewirkt dass das Fenster geschlossen wird.
void Einstellungen::on_pushButton_3_clicked() {
    close();
}
