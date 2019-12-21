#include "einstellungen.h"
#include "ui_einstellungen.h"
#include  <QLabel>
#include <QHBoxLayout>

Einstellungen::Einstellungen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Einstellungen)
{
    ui->setupUi(this);
}

Einstellungen::~Einstellungen()
{
    delete ui;
}

void Einstellungen::on_pushButton_2_clicked()
{
    QLabel *label = new QLabel();
    QHBoxLayout *layout = new QHBoxLayout();
    label->setText("Diese Anwendung ist eine Implementierung von Qwirkle. Credits: ...");
    layout->addWidget(label);
    qDeleteAll(ui->widget->children());
    Einstellungen::ui->widget->setLayout(layout);
    Einstellungen::ui->widget->update();
}

void Einstellungen::on_pushButton_clicked()
{
    QLabel *label = new QLabel();
    QHBoxLayout *layout = new QHBoxLayout();
    label->setText("Hier kommen Einstellungen hin.");
    layout->addWidget(label);
    qDeleteAll(ui->widget->children());
    Einstellungen::ui->widget->setLayout(layout);
    Einstellungen::ui->widget->update();
}

void Einstellungen::on_pushButton_3_clicked()
{
    close();
}
