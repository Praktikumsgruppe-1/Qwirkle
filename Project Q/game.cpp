/**********************************************************************/
// Datei: game.cpp
// Die Klasse Game beinhaltet das QWidget um das Fenster zu öffnen, wo
// das Spiel stattfindet. Es enthält auch die Variablen und Funktion
// zum Managen des Beutels und einige Funktionen zum Senden und Erhalten
// von Chatnachrichten. Sowie ein feldarray, in dem die Spielsteine, die
// auf das Feld gelegt werden, abgespeichert werden.
/**********************************************************************/

#include <QPixmap>
#include <QFrame>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QInputDialog>
#include <QMessageBox>
#include <QHostAddress>
#include <QScrollBar>

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


// static Variablen initialisieren
int feldarray [108][108][5];
std::vector< int > Game::beutelStackFarbe;
std::vector< int > Game::beutelStackForm;
std::vector< int > Game::beutelStackKopie;


/****************** Konstruktor *******************************************************************/
Game::Game(QWidget *parent, MainWindow *beforeWindow) :
    QWidget(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    setMinimumSize(1510,805);

    // Hauptfenster des Spiels aufbauen
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
    ui->lcdNumber->update();

    ui->scrollAreaWidgetContents->setBackgroundRole(QPalette::Highlight);

    ui->scrollArea->setMinimumSize(20,20);
    ui->scrollArea->setMaximumSize(4000,4000);
    ui->scrollAreaWidgetContents->setMaximumSize(8000,8000);

    QObject::connect(ui->scrollArea->verticalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(scrollToVCenter(int,int)));
    QObject::connect(ui->scrollArea->horizontalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(scrollToHCenter(int,int)));

    /*********************************************************************/
    // Spielfeld 108 x 108 wird aufgebaut und die kleinen Spielfelder eingefügt

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

    /************* Beutel erstellen ***************************************/
    // folgendes nur ausführen, wenn es noch nie ausgeführt wurde

    if( Game::beutelStackForm.empty() )
    {
        // alle möglichen werte werden in die Beutel geschrieben
        for ( int i = 0; i < 6; i++ )
        {
            for( int j = 0; j < 6; j++ )
            {
                for( int k = 0; k < 3; k++ )
                {
                    Game::beutelStackForm.push_back( i );
                    Game::beutelStackFarbe.push_back( j );
                    Game::beutelStackKopie.push_back( k );
                }
            }
        }
        // Beutel mischen
        Game::beutelMischen();

        /*** feldarray wird mit den Startwerten zum Spielbeginn initialisiert ***/
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
    }

    /**************** Benutzerhand initialisieren ******************************/

    Benutzerhand *icon1 = new Benutzerhand(ui->hand, Game::beutelStackFarbe.back(), Game::beutelStackForm.back());
    ui->lhand->addWidget(icon1);
    Game::beutelStackForm.pop_back();
    Game::beutelStackFarbe.pop_back();
    Game::beutelStackKopie.pop_back();

    Benutzerhand *icon2 = new Benutzerhand(ui->hand, Game::beutelStackFarbe.back(), Game::beutelStackForm.back() );
    ui->lhand->addWidget(icon2);
    Game::beutelStackForm.pop_back();
    Game::beutelStackFarbe.pop_back();
    Game::beutelStackKopie.pop_back();

    Benutzerhand *icon3 = new Benutzerhand(ui->hand, Game::beutelStackFarbe.back(), Game::beutelStackForm.back() );
    ui->lhand->addWidget(icon3);
    Game::beutelStackForm.pop_back();
    Game::beutelStackFarbe.pop_back();
    Game::beutelStackKopie.pop_back();

    Benutzerhand *icon4 = new Benutzerhand(ui->hand, Game::beutelStackFarbe.back(), Game::beutelStackForm.back() );
    ui->lhand->addWidget(icon4);
    Game::beutelStackForm.pop_back();
    Game::beutelStackFarbe.pop_back();
    Game::beutelStackKopie.pop_back();

    Benutzerhand *icon5 = new Benutzerhand(ui->hand, Game::beutelStackFarbe.back(), Game::beutelStackForm.back() );
    ui->lhand->addWidget(icon5);
    Game::beutelStackForm.pop_back();
    Game::beutelStackFarbe.pop_back();
    Game::beutelStackKopie.pop_back();

    Benutzerhand *icon6 = new Benutzerhand(ui->hand, Game::beutelStackFarbe.back(), Game::beutelStackForm.back() );
    ui->lhand->addWidget(icon6);
    Game::beutelStackForm.pop_back();
    Game::beutelStackFarbe.pop_back();
    Game::beutelStackKopie.pop_back();

     /************* Netzwerkaufbau *************************************************************/

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


/**************** Funktionen *********************************************************************/

// Destruktor
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


// aktualisiert alle Frames in dem ui des Games
void Game::updateFrames()
{
    ui->frame->update();
    ui->hand->update();
}


// gibt einen Zeiger auf das ui zurück
Ui::Game* Game::getUi()
{
    return Game::ui;
}


// mischt den Beutel
void Game::beutelMischen()
{
    std::vector< int > neuerBeutelStackFarbe;
    std::vector< int > neuerBeutelStackForm;
    std::vector< int > neuerBeutelStackKopie;

    int a = 0;

    // einem neuem Beutel die Sachen zufällig übergeben
    while( !Game::beutelStackFarbe.empty() )
    {
        a = randInt( 0, Game::beutelStackFarbe.size() - 1 );
        neuerBeutelStackFarbe.push_back( Game::beutelStackFarbe[a] );
        neuerBeutelStackForm.push_back( Game::beutelStackForm[a] );
        neuerBeutelStackKopie.push_back( Game::beutelStackKopie[a] );

        Game::beutelStackForm.erase( Game::beutelStackForm.begin() + a - 1 );
        Game::beutelStackFarbe.erase( Game::beutelStackFarbe.begin() + a - 1 );
        Game::beutelStackKopie.erase( Game::beutelStackKopie.begin() + a - 1 );
    }

    // neuen Beutel in alten Stack kopieren
    while( !neuerBeutelStackForm.empty() )
    {
        Game::beutelStackForm.push_back( neuerBeutelStackForm.back() );
        Game::beutelStackFarbe.push_back( neuerBeutelStackFarbe.back() );
        Game::beutelStackKopie.push_back( neuerBeutelStackKopie.back() );

        neuerBeutelStackForm.pop_back();
        neuerBeutelStackFarbe.pop_back();
        neuerBeutelStackKopie.pop_back();
    }
}


/********** Slotfunktione ***************************************************************************/

// Beendet das Fenster
void Game::on_pushButton_clicked()
{
    close();
}


// oeffnet das Fenster mit den Regeln
void Game::on_pushButton_2_clicked()
{
    rulesWindow *pRules = new rulesWindow;
    pRules->show();
}


// macht einen Zug rückgängig
void Game::on_pushButton_6_clicked()
{
    undoClass uC;
    uC.undoMove();
}


// oeffnet das Fenster mit den Einstellungen
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

    /*********** Punkte berechnen ******************************/
    for ( int i = 0; i <108; i++)
    {
        for (int j = 0; j <108; j++)
        {
            if(feldarray[i][j][3]==1)
            {
                spielerpunkte = spielerpunkte + points->calc(i,j);
                qDebug("Punkte werden berechnet");
            }
        }
    }
    qDebug() << spielerpunkte;
    ui->lcdNumber->display(spielerpunkte);
    ui->lcdNumber->update();

    /***** Spielsteine zählen, die bewegt wurden **************/
    int xKoordSchleife, yKoordSchleife, bewegteSteine = 0;
    for( xKoordSchleife = 0; xKoordSchleife < 108; xKoordSchleife++ )
    {
        for( yKoordSchleife = 0; yKoordSchleife < 108; yKoordSchleife++ )
        {
            if( feldarray[xKoordSchleife][yKoordSchleife][3] == 1 )
                bewegteSteine++;
        }
    }

    /*************** Spielsteine hinzufügen ***************************/
    for( int i = 0; i < bewegteSteine; i++ )
    {
        Game* pframe2 = new Game();
        QLabel *newIcon = new QLabel( );

        newIcon->setParent( undoClass::undoParent.top() );
        newIcon->setPixmap( getPixmap( Game::beutelStackFarbe.back(), Game::beutelStackForm.back() ) );
        newIcon->move( undoClass::undoCoordOldX.top(), undoClass::undoCoordOldY.top() );
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        pframe2->updateFrames();

        /*******Stacks updaten***********************/
        Game::beutelStackForm.pop_back();
        Game::beutelStackFarbe.pop_back();
        Game::beutelStackKopie.pop_back();

        undoClass::undoStack.pop();
        undoClass::undoParent.pop();
        undoClass::undoCoordOldX.pop();
        undoClass::undoCoordOldY.pop();
        undoClass::undoReihe.pop();
        undoClass::undoSpalte.pop();
        undoClass::undoPixmap.pop();
    }

    /************* undo Funktion zurücksetzen *****************************/
    while( undoClass::undoStack.empty() == false )
    {
        undoClass::undoStack.pop();
        undoClass::undoParent.pop();
        undoClass::undoCoordOldX.pop();
        undoClass::undoCoordOldY.pop();
        undoClass::undoReihe.pop();
        undoClass::undoSpalte.pop();
        undoClass::undoPixmap.pop();
    }

    /************ feldarray aktualisieren *********************************/
    int i, j;
    for ( i = 0; i < 108; i++ )
    {
        for( j = 0; j < 108; j++ )
        {
            feldarray[i][j][0] = 0;
            feldarray[i][j][3] = 0;
            //qDebug("feldarray wurde aktualisiert");
        }
    }

    SteinImFeld = 0;

}

/******************** Netzwerkfunktionen ****************************************************************************/

// eine Chatnachricht wird gesendet
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


// eine Chatnachricht wurde empfangen
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


// Verbindung zum Server ist abgebrochen
void Game::disconnectedFromServer()
{
    QMessageBox::warning(this, tr("Disconnected"), tr("The host terminated the connection"));
    ui->messageEdit->setEnabled(false);
    m_lastUserName.clear();
}


// ein Benutzer ist dem Server dazugetreten
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


// ein Benutzer hat die Verbindung unterbrochen
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


// Errormeldungen
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

