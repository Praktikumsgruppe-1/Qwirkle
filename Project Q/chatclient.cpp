#include "chatclient.h"
#include "game.h"
#include "spielfeld.h"

#include <QTcpSocket>
#include <QDataStream>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QTimer>
#include <QDebug>
#include <QJsonArray>

ChatClient::ChatClient(QObject *parent)
    : QObject(parent)
    , m_clientSocket(new QTcpSocket(this))
    , m_loggedIn(false)
{
    connect(m_clientSocket, &QTcpSocket::connected, this, &ChatClient::connected);
    connect(m_clientSocket, &QTcpSocket::disconnected, this, &ChatClient::disconnected);
    connect(m_clientSocket, &QTcpSocket::readyRead, this, &ChatClient::onReadyRead);
    connect(m_clientSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &ChatClient::error);
    connect(m_clientSocket, &QTcpSocket::disconnected, this, [this]()->void{m_loggedIn = false;});
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(ticktock()));
    timer ->start(10000); // jede x/1000 sec
}

void ChatClient::login(const QString &userName)
{
    if (m_clientSocket->state() == QAbstractSocket::ConnectedState) {
        QDataStream clientStream(m_clientSocket);
        clientStream.setVersion(QDataStream::Qt_5_7);
        QJsonObject message;
        message["type"] = QStringLiteral("login");
        message["username"] = userName;
        clientStream << QJsonDocument(message).toJson(QJsonDocument::Compact);
    }
}
void ChatClient::sendPoints(const QString &text)
{

    QDataStream clientStream(m_clientSocket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    QJsonObject points;
    points["type"] = QStringLiteral("points");
    points["text"] = text;
    clientStream << QJsonDocument(points).toJson();

}
void ChatClient::sendTurn(const QJsonArray &text)
{

    QDataStream clientStream(m_clientSocket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    QJsonObject turn;
    turn["type"] = QStringLiteral("turn");
    turn["text"] = text;
    clientStream << QJsonDocument(turn).toJson();
}
void ChatClient::sendMessage(const QString &text)
{
    if (text.isEmpty())
        return;
    QDataStream clientStream(m_clientSocket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    QJsonObject message;
    message["type"] = QStringLiteral("message");
    message["text"] = text;
    clientStream << QJsonDocument(message).toJson();
}

void ChatClient::disconnectFromHost()
{
    m_clientSocket->disconnectFromHost();
}

void ChatClient::jsonReceived(const QJsonObject &docObj)
{
    const QJsonValue typeVal = docObj.value(QLatin1String("type"));
    if (typeVal.isNull() )
        return;
    if (typeVal.toString().compare(QLatin1String("login"), Qt::CaseInsensitive) == 0) {
        if (m_loggedIn)
            return;
        const QJsonValue resultVal = docObj.value(QLatin1String("success"));
        if (resultVal.isNull() || !resultVal.isBool())
            return;
        const bool loginSuccess = resultVal.toBool();
        if (loginSuccess) {
            emit loggedIn();
            return;
        }
        const QJsonValue reasonVal = docObj.value(QLatin1String("reason"));
        emit loginError(reasonVal.toString());
    } else if (typeVal.toString().compare(QLatin1String("message"), Qt::CaseInsensitive) == 0) {
        const QJsonValue textVal = docObj.value(QLatin1String("text"));
        const QJsonValue senderVal = docObj.value(QLatin1String("sender"));
        if (textVal.isNull() )
            return;
        if (senderVal.isNull() || !senderVal.isString())
            return;
        emit messageReceived(senderVal.toString(), textVal.toString());
    } else if (typeVal.toString().compare(QLatin1String("turn"), Qt::CaseInsensitive) == 0) //turn
    {
        qDebug() << "Turn angekommen";
        allerersterStein = 1;
        qDebug() << "allerersterStein?" << allerersterStein;
        const QJsonValue textVal = docObj.value(QLatin1String("text"));
        const QJsonValue senderVal = docObj.value(QLatin1String("sender"));
        if (senderVal.isNull() || !senderVal.isString())
            return;
        QJsonArray test = textVal.toArray();
        qDebug() << "test" << test;
        Game::arrayauslesen(test);
        emit turnReceived(senderVal.toString(), textVal.toArray());
    }
    else if (typeVal.toString().compare(QLatin1String("points"), Qt::CaseInsensitive) == 0) { //points
        const QJsonValue textVal = docObj.value(QLatin1String("text"));
        const QJsonValue senderVal = docObj.value(QLatin1String("sender"));
        if (senderVal.isNull() || !senderVal.isString())
            return;
        emit messageReceived(senderVal.toString(), textVal.toString());
    } else if (typeVal.toString().compare(QLatin1String("form"), Qt::CaseInsensitive) == 0) { //form
        const QJsonValue textVal = docObj.value(QLatin1String("text"));
        const QJsonValue senderVal = docObj.value(QLatin1String("sender"));
        if (senderVal.isNull() || !senderVal.isString())
            return;
        emit formReceived(senderVal.toString(), textVal.toArray());
    } else if (typeVal.toString().compare(QLatin1String("farbe"), Qt::CaseInsensitive) == 0) { //farbe
        const QJsonValue textVal = docObj.value(QLatin1String("text"));
        const QJsonValue senderVal = docObj.value(QLatin1String("sender"));
        if (senderVal.isNull() || !senderVal.isString())
            return;
        emit farbeReceived(senderVal.toString(), textVal.toArray());
    } else if (typeVal.toString().compare(QLatin1String("kopie"), Qt::CaseInsensitive) == 0) { //kopie
        const QJsonValue textVal = docObj.value(QLatin1String("text"));
        const QJsonValue senderVal = docObj.value(QLatin1String("sender"));
        if (senderVal.isNull() || !senderVal.isString())
            return;
        emit kopieReceived(senderVal.toString(), textVal.toArray());
    } else if (typeVal.toString().compare(QLatin1String("newuser"), Qt::CaseInsensitive) == 0) {
        const QJsonValue usernameVal = docObj.value(QLatin1String("username"));
        if (usernameVal.isNull() || !usernameVal.isString())
            return;
        emit userJoined(usernameVal.toString());
    } else if (typeVal.toString().compare(QLatin1String("userdisconnected"), Qt::CaseInsensitive) == 0) {
        const QJsonValue usernameVal = docObj.value(QLatin1String("username"));
        if (usernameVal.isNull() || !usernameVal.isString())
            return;
        emit userLeft(usernameVal.toString());
    }


}

void ChatClient::connectToServer(const QHostAddress &address, quint16 port)
{
    m_clientSocket->connectToHost(address, port);
}

void ChatClient::onReadyRead()
{
    QByteArray jsonData;
    QDataStream socketStream(m_clientSocket);
    socketStream.setVersion(QDataStream::Qt_5_7);
    for (;;) {
        socketStream.startTransaction();
        socketStream >> jsonData;
        if (socketStream.commitTransaction()) {
            QJsonParseError parseError;
            const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
            if (parseError.error == QJsonParseError::NoError)
            {
                if (jsonDoc.isObject())
                    jsonReceived(jsonDoc.object());
            }
        } else {
            break;
        }
    }
}
void ChatClient::nextPlayer()
{
            // hand freischalten  fehlt
            // ticktock();
            // spielbrett aktualisiern





            // hand sperren fehlt
}

void ChatClient::ticktock()
{

    qDebug() <<"turn ";
    timer->stop();

}
void ChatClient::sendFarbe(QJsonArray &text)
{
  //  if (array.isEmpty())
  //      return;
    QDataStream clientStream(m_clientSocket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    QJsonObject turn;
    turn["type"] = QStringLiteral("farbe");
    turn["text"] = text;
    clientStream << QJsonDocument(turn).toJson();
}

void ChatClient::sendForm(QJsonArray &text)
{
  //  if (array.isEmpty())
  //      return;
    QDataStream clientStream(m_clientSocket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    QJsonObject turn;
    turn["type"] = QStringLiteral("form");
    turn["text"] = text;
    clientStream << QJsonDocument(turn).toJson();
}

void ChatClient::sendKopie(QJsonArray &text)
{
  //  if (array.isEmpty())
  //      return;
    QDataStream clientStream(m_clientSocket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    QJsonObject turn;
    turn["type"] = QStringLiteral("kopie");
    turn["text"] = text;
    clientStream << QJsonDocument(turn).toJson();
}
