/**********************************************************************/
// Datei: Einstellungen.h
// Die Klasse Einstellungen, beinhaltet die Inhalte für das Widget-Fenster
// Einstellungen, wo später noch Einstelungsmöglichkeiten hinkommen.
/**********************************************************************/
#ifndef EINSTELLUNGEN_H
#define EINSTELLUNGEN_H

#include <QWidget>
#include "ui_einstellungen.h"

namespace Ui {
class Einstellungen;
}

class Einstellungen : public QWidget {
    Q_OBJECT

public:
    explicit Einstellungen(QWidget *parent = nullptr);
    ~Einstellungen();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Einstellungen *ui;
};

#endif // EINSTELLUNGEN_H
