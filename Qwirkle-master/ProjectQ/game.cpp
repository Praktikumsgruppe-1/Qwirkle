#include "game.h"
#include "ui_game.h"
#include "benutzerhand.h"
#include "spielfeld.h"
#include "mainwindow.h"
#include "chatclient.h"
#include "chatserver.h"
#include "serverworker.h"
#include "ruleswindow.h"
#include <QPixmap>
#include <QFrame>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QInputDialog>
#include <QMessageBox>
#include <QHostAddress>


Game::Game(QWidget *parent, MainWindow *beforeWindow) :
    QWidget(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);

    /*
    QWidget *hand = new QWidget;
    ui->lhand = new QHBoxLayout(hand);
    //ui->hand
    ui->frame_2 =  new Benutzerhand(hand,3,4);
    ui->lhand->addWidget(ui->frame_2);
    */

    Benutzerhand *icon1 = new Benutzerhand(ui->hand,3,4);
    Benutzerhand *icon2 = new Benutzerhand(ui->hand,1,4);
    Benutzerhand *icon3 = new Benutzerhand(ui->hand,3,5);
    Benutzerhand *icon4 = new Benutzerhand(ui->hand,2,1);
    Benutzerhand *icon5 = new Benutzerhand(ui->hand,5,4);
    Benutzerhand *icon6 = new Benutzerhand(ui->hand,3,4);

    ui->lhand->addWidget(icon1);
    ui->lhand->addWidget(icon2);
    ui->lhand->addWidget(icon3);
    ui->lhand->addWidget(icon4);
    ui->lhand->addWidget(icon5);
    ui->lhand->addWidget(icon6);

    if ( beforeWindow != nullptr ){
        m_chatServer = beforeWindow->getServerAdress();
        m_chatClient = beforeWindow->getClientAdress();
        m_chatModel = new QStandardItemModel(this);
        m_lastUserName = beforeWindow->getLastUserName();

        beforeWindow->close();

        connect(m_chatClient, &ChatClient::userJoined, this, &Game::userJoined);
        connect(m_chatClient, &ChatClient::userLeft, this, &Game::userLeft);
        connect(ui->messageEdit, &QLineEdit::returnPressed, this, &Game::sendMessage);
        connect(m_chatClient, &ChatClient::messageReceived, this, &Game::messageReceived);

        m_chatModel->insertColumn(0);
        ui->chatView->setModel(m_chatModel);
    }
}

Game::~Game()
{
    delete ui;
}

void Game::on_pushButton_clicked()
{
    close();
}

void Game::on_pushButton_2_clicked()
{
    rulesWindow *pRules = new rulesWindow;
    pRules->show();
}

// aktualisiert alle Frames in dem ui des Games
void Game::updateFrames()
{
    ui->frame->update();
    ui->hand->update();
}

Ui::Game* Game::getUi()
{
    return Game::ui;
}

void Game::on_pushButton_6_clicked()
{
    undoClass uC;
    uC.undoMove();
}

void Game::sendMessage()
{
    m_chatClient->sendMessage(ui->messageEdit->text());
    const int newRow = m_chatModel->rowCount();
    m_chatModel->insertRow(newRow);
    m_chatModel->setData(m_chatModel->index(newRow, 0), ui->messageEdit->text());
    m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignRight | Qt::AlignVCenter), Qt::TextAlignmentRole);
    ui->messageEdit->clear();
    ui->chatView->scrollToBottom();
    m_lastUserName.clear();
}

void Game::messageReceived(const QString &sender, const QString &text)
{
    int newRow = m_chatModel->rowCount();
    if (m_lastUserName != sender) {
        m_lastUserName = sender;
        QFont boldFont;
        boldFont.setBold(true);
        m_chatModel->insertRows(newRow, 2);
        m_chatModel->setData(m_chatModel->index(newRow, 0), sender + ':');
        m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);
        m_chatModel->setData(m_chatModel->index(newRow, 0), boldFont, Qt::FontRole);
        ++newRow;
    } else {
        m_chatModel->insertRow(newRow);
    }
    m_chatModel->setData(m_chatModel->index(newRow, 0), text);
    m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);
    getUi()->chatView->scrollToBottom();
}

void Game::disconnectedFromServer()
{
    QMessageBox::warning(this, tr("Disconnected"), tr("The host terminated the connection"));
    ui->messageEdit->setEnabled(false);
    m_lastUserName.clear();
}

void Game::userJoined(const QString &username)
{
    const int newRow = m_chatModel->rowCount();
    m_chatModel->insertRow(newRow);
    m_chatModel->setData(m_chatModel->index(newRow, 0), tr("%1 Joined the Chat").arg(username));
    m_chatModel->setData(m_chatModel->index(newRow, 0), Qt::AlignCenter, Qt::TextAlignmentRole);
    m_chatModel->setData(m_chatModel->index(newRow, 0), QBrush(Qt::blue), Qt::ForegroundRole);
    ui->chatView->scrollToBottom();
    m_lastUserName.clear();
}
void Game::userLeft(const QString &username)
{
    const int newRow = m_chatModel->rowCount();
    m_chatModel->insertRow(newRow);
    m_chatModel->setData(m_chatModel->index(newRow, 0), tr("%1 Left the Chat").arg(username));
    m_chatModel->setData(m_chatModel->index(newRow, 0), Qt::AlignCenter, Qt::TextAlignmentRole);
    m_chatModel->setData(m_chatModel->index(newRow, 0), QBrush(Qt::red), Qt::ForegroundRole);
    ui->chatView->scrollToBottom();
    m_lastUserName.clear();
}

void Game::error(QAbstractSocket::SocketError socketError)
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
    ui->messageEdit->setEnabled(false);
    ui->chatView->setEnabled(false);
    m_lastUserName.clear();
}
