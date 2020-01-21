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


// Katharinas Ansatz für Spielfeld
    /******************************************/
    /*QGridLayout *gridLayout = new QGridLayout();
    for ( int i = 0; i < 181; i++ )
    {
        for ( int j = 0; j < 181; j++ )
        {
            Spielfeld *frame = new Spielfeld();
            gridLayout->addWidget( frame, i, j );
        }
    }
    ui->frame_2->setLayout( gridLayout );*/
    /******************************************/


    /*
    Spielfeld *feld01 = new Spielfeld(ui->feld);
    Spielfeld *feld02 = new Spielfeld(ui->feld);
    Spielfeld *feld03 = new Spielfeld(ui->feld);
    Spielfeld *feld04 = new Spielfeld(ui->feld);
    Spielfeld *feld05 = new Spielfeld(ui->feld);
    Spielfeld *feld06 = new Spielfeld(ui->feld);
    Spielfeld *feld07 = new Spielfeld(ui->feld);
    Spielfeld *feld08 = new Spielfeld(ui->feld);
    Spielfeld *feld09 = new Spielfeld(ui->feld);
    Spielfeld *feld10 = new Spielfeld(ui->feld);
    Spielfeld *feld11 = new Spielfeld(ui->feld);
    Spielfeld *feld12 = new Spielfeld(ui->feld);
    Spielfeld *feld13 = new Spielfeld(ui->feld);
    Spielfeld *feld14 = new Spielfeld(ui->feld);
    Spielfeld *feld15 = new Spielfeld(ui->feld);
    Spielfeld *feld16 = new Spielfeld(ui->feld);
    Spielfeld *feld17 = new Spielfeld(ui->feld);
    Spielfeld *feld18 = new Spielfeld(ui->feld);


    ui->lfeld2->addWidget(feld01);
    ui->lfeld2->addWidget(feld02);
    ui->lfeld2->addWidget(feld03);
    ui->lfeld2->addWidget(feld04);
    ui->lfeld2->addWidget(feld05);
    ui->lfeld2->addWidget(feld06);
    ui->lfeld2->addWidget(feld07);
    ui->lfeld2->addWidget(feld08);
    ui->lfeld2->addWidget(feld09);
    ui->lfeld2->addWidget(feld10);
    ui->lfeld2->addWidget(feld11);
    ui->lfeld2->addWidget(feld12);
    ui->lfeld2->addWidget(feld13);
    ui->lfeld2->addWidget(feld14);
    ui->lfeld2->addWidget(feld15);
    ui->lfeld2->addWidget(feld16);
    ui->lfeld2->addWidget(feld17);
    ui->lfeld2->addWidget(feld18);
    */

    ui->scrollArea->setMinimumSize(20,20);
    //ui->scrollArea->setMaximumSize(1600,900);

    ui->scrollAreaWidgetContents->setMinimumSize(20,20);
    ui->scrollAreaWidgetContents->setMaximumSize(1600,900);

    ui->hintern->setMinimumSize(20,20);
    ui->hintern->setMaximumSize(4000,4000);

    //ab hier müsste man das denke ich auch in einer for-schleife machen können, an der sitze ich gerade, wegen der Benennung harkt es noch ein bisschen

    Spielfeld *feld001x001 = new Spielfeld;
    Spielfeld *feld001x002 = new Spielfeld;
    Spielfeld *feld001x003 = new Spielfeld;
    Spielfeld *feld002x001 = new Spielfeld;
    Spielfeld *feld002x002 = new Spielfeld;
    Spielfeld *feld002x003 = new Spielfeld;
    Spielfeld *feld003x001 = new Spielfeld;
    Spielfeld *feld003x002 = new Spielfeld;
    Spielfeld *feld003x003 = new Spielfeld;

    Spielfeld felda[3][3] =
    {
       {feld001x001,feld001x002,feld001x003},
       {feld002x001,feld002x002,feld002x003},
       {feld003x001,feld003x002,feld003x003},
    };

    int i=0, j=0;

    for (i=1;i>3;i++)
    {
        for (j=1;j>3;j++)
        {
            ui->lfeld->addWidget(felda(i,j));
        }
    }

    /*
    ui->lfeld->addWidget(feld001x001,1,1,1,1);
    ui->lfeld->addWidget(feld001x002,1,2,1,1);
    ui->lfeld->addWidget(feld001x003,1,3,1,1);
    ui->lfeld->addWidget(feld002x001,2,1,1,1);
    ui->lfeld->addWidget(feld002x002,2,2,1,1);
    ui->lfeld->addWidget(feld002x003,2,3,1,1);
    ui->lfeld->addWidget(feld003x001,3,1,1,1);
    ui->lfeld->addWidget(feld003x002,3,2,1,1);
    ui->lfeld->addWidget(feld003x003,3,3,1,1);
    */

/* hier mein erster Versuch für die for-Schleifen

//die  181 "Reihen" unseres Raster werden erstellt

for (i=0;i>181;i++)
{
    QHBoxLayout *(pointer i oder so) = new QHBoxLayout;
}

//in das große QVBoxlayout werden die 181 "Reihen" eingefügt

for (i=0;i>181;i++)
{
    vlfeld->addLayout(h(nummer des HBoxLayout));
}

//es werden 181x181 Spielfelder erzeugt

for (i=0;i>181;i++)
{
    for (j=0;j>181;j++)
    {
        Spielfeld *(pointer auf i und j oder so, für eine ordentliche indexbenennung) = new Spielfeld;
        (wahrscheinlich noch Size einstellen)
    }
}

//in jede der 181 "Reihen" werden 181 Spielfelder eingefügt

for (i=0;i>181;i++)
{
    for (j=0;j>181;i++)
    {
        h(HBoxlayout*nummer)feld->addWidget(feld(indexbenennung));
    }
}

*/

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
