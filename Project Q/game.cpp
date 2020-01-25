#include "game.h"
#include "ui_game.h"
#include "benutzerhand.h"
#include "spielfeld.h"
#include "mainwindow.h"
#include "chatclient.h"
#include "chatserver.h"
#include "serverworker.h"
#include "ruleswindow.h"
#include "punkte.h"
#include "regeln.h"
#include "tauschen.h"
#include "undo.h"
#include "mainwindow.h"
#include "einstellungen.h"
#include "spielfeld.h"

#include <QPixmap>
#include <QFrame>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QInputDialog>
#include <QMessageBox>
#include <QHostAddress>
#include <QScrollBar>


int feldarray [108][108][5];
bool beutel [6][6][3];

Game::Game(QWidget *parent, MainWindow *beforeWindow) :
    QWidget(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    setMinimumSize(1510,805);

    //versuche das Fenster dynamisch größenanpassbar zu machen
    QVBoxLayout *fenster = new QVBoxLayout(this);
    QFrame *unten = new QFrame;
    QHBoxLayout *lunten = new QHBoxLayout(unten);

    lunten->addWidget(ui->unten_links);
    lunten->addWidget(ui->unten_mitte);
    lunten->addWidget(ui->unten_rechts);
    unten->setLayout(lunten);

    fenster->addWidget(ui->scrollArea);
    fenster->addWidget(unten);

    ui->einstellungen->setIcon(QPixmap(":/images/einstellungen"));
    ui->pushButton_7->setIcon(QPixmap(":/images/right1"));

    ui->lcdNumber->display(spielerpunkte);

    /*
    QWidget *hand = new QWidget;
    ui->lhand = new QHBoxLayout(hand);
    //ui->hand
    ui->frame_2 =  new Benutzerhand(hand,3,4);
    ui->lhand->addWidget(ui->frame_2);
    */

    /****************************************************************************/

    //Versuch das Hintergrundbild schöner zu machen
    ui->scrollAreaWidgetContents->setBackgroundRole(QPalette::Highlight);

    // Spielfeld 108 x 108 wird aufgebaut und die kleinen Spielfelder eingefügt

    ui->scrollArea->setMinimumSize(20,20);
    ui->scrollArea->setMaximumSize(4000,4000);
    ui->scrollAreaWidgetContents->setMaximumSize(8000,8000);

    QObject::connect(ui->scrollArea->verticalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(scrollToVCenter(int,int)));
    QObject::connect(ui->scrollArea->horizontalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(scrollToHCenter(int,int)));


    for ( int i = 0; i < 108; i++ )

    {
        ui->lfeld->setRowMinimumHeight( i, 75 );
        ui->lfeld->setColumnMinimumWidth( i, 75 );
        for ( int j = 0; j < 108; j++ )
        {
            frame[i][j] = new Spielfeld( nullptr, i, j );
            ui->lfeld->addWidget( frame[i][j], i, j );
        }
    }

    ui->scrollAreaWidgetContents->setLayout( ui->lfeld );
    ui->scrollArea->setWidget( ui->scrollAreaWidgetContents );

    //der beutel-inhalt wird auf wahr initialisiert zum Spielbeginn
    for ( int i = 0; i < 6; i++ )
    {
        for ( int j = 0; j < 6; j++)
        {
            for (int h = 0; h < 3; h++)
            {
                beutel[i][j][h] = true;
            }
        }
    }

    /****************************************************************************/
    //funktion für den beutel und die benutzerhand

    int r,g ;

    do
    {
        r= randInt(0,5);
        g= randInt(0,5);

        Benutzerhand *icon1 = new Benutzerhand(ui->hand, r,g);
        ui->lhand->addWidget(icon1);
    }

    while (!(beutel[r][g][0] || beutel[r][g][1] || beutel[r][g][2]));

    do
    {
        r= randInt(0,5);
        g= randInt(0,5);

        Benutzerhand *icon2 = new Benutzerhand(ui->hand, r,g);
        ui->lhand->addWidget(icon2);
    }

    while (!(beutel[r][g][0] || beutel[r][g][1] || beutel[r][g][2]));

    do
    {
        r= randInt(0,5);
        g= randInt(0,5);

        Benutzerhand *icon3 = new Benutzerhand(ui->hand, r,g);
        ui->lhand->addWidget(icon3);
    }

    while (!(beutel[r][g][0] || beutel[r][g][1] || beutel[r][g][2]));

    do
    {
        r= randInt(0,5);
        g= randInt(0,5);

        Benutzerhand *icon4 = new Benutzerhand(ui->hand, r,g);
        ui->lhand->addWidget(icon4);
    }

    while (!(beutel[r][g][0] || beutel[r][g][1] || beutel[r][g][2]));

    do
    {
        r= randInt(0,5);
        g= randInt(0,5);

        Benutzerhand *icon5 = new Benutzerhand(ui->hand, r,g);
        ui->lhand->addWidget(icon5);
    }

    while (!(beutel[r][g][0] || beutel[r][g][1] || beutel[r][g][2]));

    do
    {
        r= randInt(0,5);
        g= randInt(0,5);

        Benutzerhand *icon6 = new Benutzerhand(ui->hand, r,g);
        ui->lhand->addWidget(icon6);
    }

    while (!(beutel[r][g][0] || beutel[r][g][1] || beutel[r][g][2]));




    //feldarray wird mit den Startwerten zum Spielbeginn initialisiert
    for ( int i = 0; i < 108; i++ )
    {
        for ( int j = 0; j < 108; j++)
        {
          feldarray[i][j][0] = 0;
          feldarray[i][j][1] = 9;
          feldarray[i][j][2] = 9;
          feldarray[i][j][3] = 0;
          feldarray[i][j][4] = 0;
        }
    }

     /****************************************************************************/
    // Netzwerkaufbau

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
    for( int i = 0; i < 108; i++ )
    {
        for (int j = 0; j < 108; j++) {
            delete &(frame[i][j]);
        }
    }

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


void Game::on_einstellungen_clicked()
{
    Einstellungen* pEinst = new Einstellungen();
    pEinst->show();
}

// scrollt zur horizontalen Mitte des Spielfeldes
void Game::scrollToHCenter(int min, int max)
{
    (void) min;
    if (max > scrollBarHMax)
        ui->scrollArea->horizontalScrollBar()->setValue( ui->scrollArea->horizontalScrollBar()->maximum() / 2 );
    scrollBarHMax = max;
}

// scrollt zur vertikalen Mitte des Spielfeldes
void Game::scrollToVCenter(int min, int max)
{
    (void) min;
    if (max > scrollBarVMax)
        ui->scrollArea->verticalScrollBar()->setValue( ui->scrollArea->verticalScrollBar()->maximum() / 2 );
    scrollBarVMax = max;
}

// Abgabefunktion zum Rundenende
void Game::on_pushButton_7_clicked()
{
    Punkte *points = new Punkte;

    for ( int i = 0; i <108; i++)
    {
        for (int j = 0; j <108; j++)
        {
            if(feldarray[i][j][3]==1)
                spielerpunkte = spielerpunkte + points->calc(i,j);
        }
    }

    // Spielsteine zählen, die bewegt wurden
    int xKoordSchleife, yKoordSchleife, bewegteSteine = 0;
    for( xKoordSchleife = 0; xKoordSchleife < 108; xKoordSchleife++ )
    {
        for( yKoordSchleife = 0; yKoordSchleife < 108; yKoordSchleife++ )
        {
            if( feldarray[xKoordSchleife][yKoordSchleife][3] == 1 )
                bewegteSteine++;
        }
    }

    // Spielsteine hinzufügen
    int a = 0, b = 0, c = 0;
    for( int i = 0; i < bewegteSteine; i++ )
    {
        {                                               // neuen Stein generieren, der noch im Beutel ist
            a = randInt( 0, 5 );
            b = randInt( 0, 5);
            c = randInt( 0, 2 );
        }
        while ( beutel[a][b][c] == false );
        beutel[a][b][c] = false;

        Game* pframe2 = new Game();
        QLabel *newIcon = new QLabel( );

/************************************************************************************************************************************************/
        // undoClass::undoParent.top() == ui->hand funktioniert nicht!
        if( undoClass::undoParent.top() == ui->hand )   // wenn der letze aus dem UndoMove aus der Benutzerhand stammt, soll der
        {                                               // Stein auf die Koordinaten dieses UndoMove Objekts gelegt werden
            newIcon->setParent( undoClass::undoParent.top() );
            newIcon->setPixmap( getPixmap( a, b ) );
            newIcon->move( undoClass::undoCoordOldX.top(), undoClass::undoCoordOldY.top() );
            newIcon->show();
            newIcon->setAttribute(Qt::WA_DeleteOnClose);

            pframe2->updateFrames();

            qDebug() << "Hallo";

        }

        undoClass::undoStack.pop();                     // Undo Stack um eine UndoMove Objekt kleiner machen
        undoClass::undoParent.pop();
        undoClass::undoCoordOldX.pop();
        undoClass::undoCoordOldY.pop();
        undoClass::undoCoordNewX.pop();
        undoClass::undoCoordNewY.pop();
        undoClass::undoPixmap.pop();
    }

    // undo Funktion zurücksetzen
    while( undoClass::undoStack.empty() == false )
    {
        undoClass::undoStack.pop();
        undoClass::undoParent.pop();
        undoClass::undoCoordOldX.pop();
        undoClass::undoCoordOldY.pop();
        undoClass::undoCoordNewX.pop();
        undoClass::undoCoordNewY.pop();
        undoClass::undoPixmap.pop();
    }

    // feldarray aktualisieren
    int i, j;
    for ( i = 0; i < 180; i++ )
    {
        for( j = 0; j < 180; j++ )
        {
            feldarray[i][j][0] = 0;
            feldarray[i][j][3] = 0;
        }
    }
}

/************************************************************************************************/
// Netzwerkfunktionen

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

