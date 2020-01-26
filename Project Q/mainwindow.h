/**********************************************************************/
// Datei: mainwindow.h
// Die Klasse MainWindow enthält das Fenster welches als allersrstes
// geöffnet wird. Die Klasse stellt auch die Verbindung zwischen Client
// und Server her.
/**********************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractSocket>

class ChatServer;
class ChatClient;
class QStandardItemModel;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ChatServer* getServerAdress();
    ChatClient* getClientAdress();
    QString getLastUserName();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_startStopButton_clicked();

    void toggleStartServer();
    void logMessage(const QString &msg);
    void attemptConnection();
    void connectedToServer();
    void attemptLogin(const QString &userName);
    void loggedIn();
    void loginFailed(const QString &reason);
    void disconnectedFromServer();
    void error(QAbstractSocket::SocketError socketError);


private:
    Ui::MainWindow *ui;

    ChatServer *m_chatServer;
    ChatClient *m_chatClient;
    QString m_lastUserName;

    friend class Game;
};
#endif // MAINWINDOW_H
