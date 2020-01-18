#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QAbstractSocket>
#include "tauschen.h"
#include "undo.h"
#include "mainwindow.h"

class ChatServer;
class ChatClient;
class QStandardItemModel;

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr, MainWindow *beforeWindow = nullptr);
    ~Game();

    Ui::Game* getUi();
    void updateFrames();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_6_clicked();

    void messageReceived(const QString &sender, const QString &text);
    void sendMessage();
    void disconnectedFromServer();
    void error(QAbstractSocket::SocketError socketError);
    void userJoined(const QString &username);
    void userLeft(const QString &username);

private:
    Ui::Game *ui;

    ChatServer *m_chatServer;
    ChatClient *m_chatClient;
    QStandardItemModel *m_chatModel;
    QString m_lastUserName;

    friend class MainWindow;
};

#endif // GAME_H
