/**********************************************************************/
// Datei: mainwindow.cpp
// Die Klasse MainWindow enthält das Fenster welches als allersrstes
// geöffnet wird. Die Klasse stellt auch die Verbindung zwischen Client
// und Server her.
/**********************************************************************/

#include <QStandardItemModel>
#include <QInputDialog>
#include <QMessageBox>
#include <QHostAddress>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include "ui_game.h"
#include "chatserver.h"
#include "chatclient.h"


/************ Memberfunktionen ************************************************************/

// Konstruktor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_chatServer(new ChatServer(this))
    , m_chatClient(new ChatClient(this))
{
    ui->setupUi(this);

    connect(ui->startStopButton, &QPushButton::clicked, this, &MainWindow::toggleStartServer);
    connect(m_chatServer, &ChatServer::logMessage, this, &MainWindow::logMessage);
    connect(m_chatClient, &ChatClient::connected, this, &MainWindow::connectedToServer);
    connect(m_chatClient, &ChatClient::loggedIn, this, &MainWindow::loggedIn);
    connect(m_chatClient, &ChatClient::loginError, this, &MainWindow::loginFailed);
    connect(m_chatClient, &ChatClient::disconnected, this, &MainWindow::disconnectedFromServer);
    connect(m_chatClient, &ChatClient::error, this, &MainWindow::error);
    connect(ui->connectButton, &QPushButton::clicked, this, &MainWindow::attemptConnection);
}


// Destruktor
MainWindow::~MainWindow()
{
    delete ui;
}


/*************************** Slotfunktionen ************************************************/


void MainWindow::on_pushButton_clicked()
{

}


// öffnet das neue Fenster in dem das Spiel stattfindet
void MainWindow::on_pushButton_3_clicked()
{
    Game *pGame = new Game( nullptr, this );
    pGame->show();
}


/************************* Netzwerkunftionen ************************************************/

ChatServer* MainWindow::getServerAdress(){
    return m_chatServer;
}

ChatClient* MainWindow::getClientAdress(){
    return m_chatClient;
}

QString MainWindow::getLastUserName(){
    return m_lastUserName;
}

void MainWindow::toggleStartServer()
{


    if (m_chatServer->isListening()) {
        m_chatServer->stopServer();
        ui->startStopButton->setText(tr("Start Server"));
        logMessage(QStringLiteral("Server Stopped"));
    } else {
        if (!m_chatServer->listen(QHostAddress::Any, 1967)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to start the server"));
            return;
        }
        logMessage(QStringLiteral("Server Started"));
        ui->startStopButton->setText(tr("Stop Server"));
    }
}

void MainWindow::logMessage(const QString &msg)
{
    ui->logEditor->appendPlainText(msg + '\n');
}

void MainWindow::attemptConnection()
{

    const QString hostAddress = QInputDialog::getText(
        this
        , tr("Chose Server")
        , tr("Server Address")
        , QLineEdit::Normal
        , QStringLiteral("127.0.0.1")
    );
    if (hostAddress.isEmpty())
        return;
    ui->connectButton->setEnabled(false);
    m_chatClient->connectToServer(QHostAddress(hostAddress), 1967);
}

void MainWindow::connectedToServer()
{
    const QString newUsername = QInputDialog::getText(this, tr("Chose Username"), tr("Username"));
    if (newUsername.isEmpty()){
        return m_chatClient->disconnectFromHost();
    }
    attemptLogin(newUsername);
}

void MainWindow::attemptLogin(const QString &userName)
{
    m_chatClient->login(userName);
}

void MainWindow::loggedIn()
{
    m_lastUserName.clear();
}

void MainWindow::loginFailed(const QString &reason)
{
    QMessageBox::critical(this, tr("Error"), reason);
    connectedToServer();
}

void MainWindow::disconnectedFromServer()
{
    QMessageBox::warning(this, tr("Disconnected"), tr("The host terminated the connection"));
    ui->connectButton->setEnabled(true);
    ui->startStopButton->setEnabled(true);
    m_lastUserName.clear();
}

void MainWindow::error(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
    case QAbstractSocket::ProxyConnectionClosedError:
        return;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::critical(this, tr("Error"), tr("The host refused the connection"));
        break;
    case QAbstractSocket::ProxyConnectionRefusedError:
        QMessageBox::critical(this, tr("Error"), tr("The proxy refused the connection"));
        break;
    case QAbstractSocket::ProxyNotFoundError:
        QMessageBox::critical(this, tr("Error"), tr("Could not find the proxy"));
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::critical(this, tr("Error"), tr("Could not find the server"));
        break;
    case QAbstractSocket::SocketAccessError:
        QMessageBox::critical(this, tr("Error"), tr("You don't have permissions to execute this operation"));
        break;
    case QAbstractSocket::SocketResourceError:
        QMessageBox::critical(this, tr("Error"), tr("Too many connections opened"));
        break;
    case QAbstractSocket::SocketTimeoutError:
        QMessageBox::warning(this, tr("Error"), tr("Operation timed out"));
        return;
    case QAbstractSocket::ProxyConnectionTimeoutError:
        QMessageBox::critical(this, tr("Error"), tr("Proxy timed out"));
        break;
    case QAbstractSocket::NetworkError:
        QMessageBox::critical(this, tr("Error"), tr("Unable to reach the network"));
        break;
    case QAbstractSocket::UnknownSocketError:
        QMessageBox::critical(this, tr("Error"), tr("An unknown error occured"));
        break;
    case QAbstractSocket::UnsupportedSocketOperationError:
        QMessageBox::critical(this, tr("Error"), tr("Operation not supported"));
        break;
    case QAbstractSocket::ProxyAuthenticationRequiredError:
        QMessageBox::critical(this, tr("Error"), tr("Your proxy requires authentication"));
        break;
    case QAbstractSocket::ProxyProtocolError:
        QMessageBox::critical(this, tr("Error"), tr("Proxy comunication failed"));
        break;
    case QAbstractSocket::TemporaryError:
    case QAbstractSocket::OperationError:
        QMessageBox::warning(this, tr("Error"), tr("Operation failed, please try again"));
        return;
    default:
        Q_UNREACHABLE();
    }
    ui->connectButton->setEnabled(true);
    m_lastUserName.clear();
}
