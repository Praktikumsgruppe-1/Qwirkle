#ifndef LOBBYERST_H
#define LOBBYERST_H

#include <QWidget>

namespace Ui {
class LobbyErst;
}

class LobbyErst : public QWidget
{
    Q_OBJECT

public:
    explicit LobbyErst(QWidget *parent = nullptr);
    ~LobbyErst();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LobbyErst *ui;
};

#endif // LOBBYERST_H
