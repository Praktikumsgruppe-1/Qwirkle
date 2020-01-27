/**********************************************************************/
// Datei: chatclient.h
// Programmebeschreibung:
/**********************************************************************/
#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>

class QHostAddress;
class QJsonDocument;

class ChatClient : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY( ChatClient )

public:
    explicit ChatClient( QObject *parent = nullptr );

public slots:
    void connectToServer( const QHostAddress &address, quint16 port );
    void login( const QString &userName );
    void sendMessage( const QString &text );
    void sendPoints( const QString &text );
    void sendTurn( const QJsonArray &text );
    void disconnectFromHost( );
    void nextPlayer( );
    void sendFarbe(QJsonArray &array);
    void sendForm(QJsonArray &array);
    void sendKopie(QJsonArray &array);

private slots:
    void onReadyRead( );
    void ticktock( );

signals:
    void connected( );
    void loggedIn( );
    void loginError( const QString &reason );
    void disconnected( );
    void messageReceived( const QString &sender, const QString &text );
    void error( QAbstractSocket::SocketError socketError );
    void userJoined( const QString &username );
    void userLeft( const QString &username );
    void formReceived(const QString &sender, const QJsonArray &text);
    void turnReceived(const QString &sender, const QJsonArray &text);
    void farbeReceived(const QString &sender, const QJsonArray &text);
    void kopieReceived(const QString &sender, const QJsonArray &text);

private:
    QTcpSocket *m_clientSocket;
    bool m_loggedIn;
    void jsonReceived( const QJsonObject &doc );
    QTimer *timer;
};

#endif // CHATCLIENT_H
