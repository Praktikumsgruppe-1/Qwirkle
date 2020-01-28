/**********************************************************************/
// Datei: game.h
// Die Klasse Game beinhaltet das QWidget um das Fenster zu öffnen, wo
// das Spiel stattfindet. Es enthält auch die Variablen und Funktion
// zum Managen des Beutels und einige Funktionen zum Senden und Erhalten
// von Chatnachrichten. Sowie ein feldarray, in dem die Spielsteine, die
// auf das Feld gelegt werden, abgespeichert werden.
/**********************************************************************/
#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QScrollArea>
#include <QAbstractSocket>
#include <vector>

class ChatServer;
class ChatClient;
class QStandardItemModel;
class MainWindow;
class Spielfeld;

namespace Ui
{
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr, MainWindow *beforeWindow = nullptr);
    ~Game();

    Ui::Game *ui;
    Spielfeld *frame[108][108];

    static std::vector< int > beutelStackFarbe;
    static std::vector< int > beutelStackForm;
    static std::vector< int > beutelStackKopie;

    Ui::Game* getUi();
    void updateFrames();

    static void beutelMischen();

    void endcheck();
    bool spielende = false;
    int extrapunkte = 0;
    //gewinnerEnde(int spielerpunkte1, spielerpunkte2, spielerpunkte3, spielerpunkte4);   ist halt noch die frage wie das geregelt ist, wenn es weniger Spieler gibt

    bool pass = false;
    bool passcheck(int a);
    int bewegteSteinef();
    void bewegteSteinej();

    static void arrayauslesen(QJsonObject &a);
    void feldarrayAktualisieren( int array[4] );
    static void formAktualisieren(QJsonArray);
    static void farbeAktualisieren(QJsonArray);
    static void kopieAktualisieren(QJsonArray);



private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_6_clicked();
    void scrollToHCenter(int, int );
    void scrollToVCenter(int, int );
    void on_pushButton_7_clicked();
    void on_einstellungen_clicked();

    void messageReceived(const QString &sender, const QString &text);
    void sendMessage();
    void sendTurn();
    void sendPoints();
    void disconnectedFromServer();
    void error(QAbstractSocket::SocketError socketError);
    void userJoined(const QString &username);
    void userLeft(const QString &username);

private:

    int scrollBarHMax = 0;
    int scrollBarVMax = 0;
    int spielerpunkte = 0;

    ChatServer *m_chatServer;
    ChatClient *m_chatClient;
    QStandardItemModel *m_chatModel;
    QString m_lastUserName;

    friend class MainWindow;
    friend class Spielfeld;
    friend class Tauschen;
};

extern int feldarray [108][108][5];                                   //startwerte: 0,9,9,0,?
//0 : erster Stein der vom Spieler in seiner Runde gelegt wird
//1 : die Farbe
//2 : die Form
//3 : markiert ob der Stein in der Runde des Spielers neu gelegt wurde
//?4 : welche Kopie von dem Stein ist es (es gibt immer 3)
#endif // GAME_H
