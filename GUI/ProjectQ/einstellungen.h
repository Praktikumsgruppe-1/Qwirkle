#ifndef EINSTELLUNGEN_H
#define EINSTELLUNGEN_H

#include <QWidget>

namespace Ui {
class Einstellungen;
}

class Einstellungen : public QWidget
{
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
