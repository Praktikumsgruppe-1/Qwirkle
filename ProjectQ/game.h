#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QScrollArea>
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

    Spielfeld *frame[108][108];

    bool *beutel [6][6][3];
    //0 : die Farbe
    //1 : die Form
    //2 : die Kopie


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_6_clicked();
    void scrollToHCenter(int, int );
    void scrollToVCenter(int, int );

    void messageReceived(const QString &sender, const QString &text);
    void sendMessage();
    void disconnectedFromServer();
    void error(QAbstractSocket::SocketError socketError);
    void userJoined(const QString &username);
    void userLeft(const QString &username);

    void on_pushButton_7_clicked();

private:
    Ui::Game *ui;
    int scrollBarHMax = 0;
    int scrollBarVMax = 0;

    int spielerpunkte = 0;

    ChatServer *m_chatServer;
    ChatClient *m_chatClient;
    QStandardItemModel *m_chatModel;
    QString m_lastUserName;

    friend class MainWindow;
};

extern int *feldarray [108][108][5];                                   //startwerte: 0,9,9,0,?
//0 : erster Stein der vom Spieler in seiner Runde gelegt wird
//1 : die Farbe
//2 : die Form
//3 : markiert ob der Stein in der Runde des Spielers neu gelegt wurde
//?4 : welche Kopie von dem Stein ist es (es gibt immer 3)


#endif // GAME_H
