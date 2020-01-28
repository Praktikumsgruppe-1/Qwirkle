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
#include <QJsonArray>
#include <QJsonObject>

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
#include "turn.h"
#include "stdio.h"
#include "stdlib.h"

// static Variablen initialisieren
int feldarray [108][108][5];
std::vector< int > Game::beutelStackFarbe;
std::vector< int > Game::beutelStackForm;
std::vector< int > Game::beutelStackKopie;
//Turn spielzug;

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
        qDebug() << "beutel gemischt im Game_Konstruktor mit " <<  Game::beutelStackFarbe.size() << "steinen im Beutel";

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
    if(allerersterStein == 0)
    {
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
        qDebug() << "Anzahl Steine im Beutel nach der benutzerhand" << Game::beutelStackFarbe.size();
    }

     /************* Netzwerkaufbau *************************************************************/

    if ( beforeWindow != nullptr )
    {
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
    qDebug() << "Der Beutel wird gemischt" ;
    std::vector< int > neuerBeutelStackFarbe;
    std::vector< int > neuerBeutelStackForm;
    std::vector< int > neuerBeutelStackKopie;

    qDebug() << "Anzahl Steine im Beutel" << Game::beutelStackFarbe.size();

    int a = 0;

    // einem neuem Beutel die Sachen zufällig übergeben
    while( !Game::beutelStackFarbe.empty() )
    {
        a = randInt( 0, Game::beutelStackFarbe.size() - 1 );
        neuerBeutelStackFarbe.push_back( Game::beutelStackFarbe[a] );
        neuerBeutelStackForm.push_back( Game::beutelStackForm[a] );
        neuerBeutelStackKopie.push_back( Game::beutelStackKopie[a] );

        Game::beutelStackForm.erase( Game::beutelStackForm.begin() + a );
        Game::beutelStackFarbe.erase( Game::beutelStackFarbe.begin() + a );
        Game::beutelStackKopie.erase( Game::beutelStackKopie.begin() + a );
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


bool Game::passcheck(int a)
{
  if(a==0)
  {
      pass = true;
  }

  return pass;
};


void Game::bewegteSteinej()
{
    qDebug() << "bewegteSteinej";
    int farbeStein;
    int formStein;
    Turn spielzug;
    int x, y;
    for( x = 0; x < 108; x++ )
    {
        for( y = 0; y < 108; y++ )
        {
            if( feldarray[x][y][3] == 1 )
            {
                farbeStein = feldarray[x][y][1];
                formStein = feldarray[x][y][2];
                spielzug.addStein(x, y, farbeStein, formStein);
                qDebug() << "Farbe: " << feldarray[x][y][1] << "Form :" << feldarray[x][y][2] << "Koordinaten: " << x << y;
            }
        }
    }

    QJsonArray turn = spielzug.steineToJson();
    qDebug() << turn;
    m_chatClient->sendTurn(turn);
};

int Game::bewegteSteinef()
{
    int x, y, bewegteSteine = 0;
    for( x = 0; x < 108; x++ )
    {
        for( y = 0; y < 108; y++ )
        {
            if( feldarray[x][y][3] == 1 )
            {
                bewegteSteine++;
            }
        }
    }
    return bewegteSteine;
};

void Game::arrayauslesen(QJsonObject &a)
{
   qDebug() << "arrayauslesen" << a;
   //int *dummyarray = (int *) malloc (4*sizeof (int));
   int anzahlSteine = a.size();
   //Game *pdum = new Game();

   for (int i = 0; i < anzahlSteine; i++)
   {
       qDebug() << "bin in der for schleife vom auslesen"  << a;
      /*
      dummyarray[0] = a.at(i)[1].toArray()[0].toInt();
      dummyarray[1] = a.at(i).toArray()[1].toInt();
      dummyarray[2] = a.at(i).toArray()[2].toInt();
      dummyarray[3] = a.at(i).toArray()[3].toInt();
      pdum->feldarrayAktualisieren(dummyarray);
      qDebug() << "feldarrayaktualisiert";
      */
   }
};


void Game::feldarrayAktualisieren( int array[4] )           // Farbe, Form, x, y
{
    qDebug() << "feladarray auslesen mit dem array:" << array[0] << array[1] << array[2] << array[3];
    // feldarray aktualisieren
    feldarray[ array[2] ][ array[3] ][ 0 ] = 0 ;
    feldarray[ array[2] ][ array[3] ][ 1 ] = array[0] ;
    feldarray[ array[2] ][ array[3] ][ 2 ] = array[1] ;
    feldarray[ array[2] ][ array[3] ][ 3 ] = 0 ;

    // Spielstein erstellen im feld
    QLabel *newIcon = new QLabel( );
    newIcon->setPixmap( getPixmap( array[0], array[1] ) );
    ui->lfeld->addWidget( newIcon,  array[2], array[3] );
    newIcon->show();
    newIcon->setAttribute(Qt::WA_DeleteOnClose);
}

/*
void Game::formAktualisieren(QJsonArray ar)
{
    Game::beutelStackForm = json::toVec(ar);
    return;
}

void Game::farbeAktualisieren(QJsonArray ar)
{
    Game::beutelStackFarbe = json::toVec(ar);
    return;
}

void Game::kopieAktualisieren(QJsonArray ar)
{
    Game::beutelStackKopie = json::toVec(ar);
    return;
}
*/
/*        hier fehlt noch die Übergabe der pass anzahl und der spieleranzahl
void Game::endcheck()
{
    if(Game::beutelStackFarbe.empty() && pass==spieleranzahl)                                                  // alle haben gepasst, und der beutel ist leer
    {
        spielende = true;
    }

    else if(Game::beutelStackFarbe.empty() && undoClass::undoStack.size() == 6)                                // Beutel und Hand leer
    {
        spielende = true;
        extrapunkte = 6;
    }

    return; // Was soll geschehen wenn das Spiel vorbei ist? Beendet sich das Fenster, oder kann man einfach nichts mehr machen, bzw ich denke es sollte bool ausgeben und eine andere Funktion guckt und sobald das true ist, triggert die den schluss
};
*/

/*
Game::gewinnerEnde(int spielerpunkte1, spielerpunkte2, spielerpunkte3, spielerpunkte4);
{
    int maximum;
    if (spielerpunkte1 >= spielerpunkte2 && spielerpunkte1 >= spielerpunkte3 && spielerpunkte1 >= spielerpunkte4)
       maximum = spielerpunkte1;
    else if (spielerpunkte2 >= spielerpunkte1 && spielerpunkte2 >= spielerpunkte3 && spielerpunkte2 >= spielerpunkte4)
       maximum = spielerpunkte2;
    else if (spielerpunkte3 >= spielerpunkte1 && spielerpunkte3 >= spielerpunkte2 && spielerpunkte3 >= spielerpunkte4)
       maximum = spielerpunkte3;
    else
       maximum = spielerpunkte4;
    //hier wird das ende getriggert, wie auch immer das aussieht
    //er müsste jetzt zum ausgeben die spielerpunkte mit dem spieler verknüpfen
};
*/

/********** Slotfunktionen ***************************************************************************/

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
    // hier fehlt dann bei den Punkten noch die Unterscheidung der Spieler
    if(passcheck(bewegteSteinef())==false)
    {
        qDebug()<< "die alten Spielerpunkte:" << spielerpunkte;
        spielerpunkte = spielerpunkte + points->calc(undoClass::undoReihe.top(),undoClass::undoSpalte.top());
        qDebug("Punkte werden berechnet");
    }


    qDebug()<< "allerersterStein:" << allerersterStein;

    if( bewegteSteinef() == 1 && spielerpunkte == 0 )
    {
        spielerpunkte++;
    }
    qDebug()<< "die neuen Spielerpunkte:" << spielerpunkte;

    ui->lcdNumber->display(spielerpunkte);
    ui->lcdNumber->update();


    qDebug() << "Anzahl der bewegten Steine:" << bewegteSteinef();

    /*************** Spielsteine hinzufügen ***************************/
    for( int i = 0; i < bewegteSteinef() && !Game::beutelStackForm.empty(); i++ )
    {
        qDebug() << "Spielsteine werden hinzugefügt für:" << bewegteSteinef();
        qDebug() << "Anzahl Steine im Beutel" << Game::beutelStackFarbe.size();
        Game* pframe2 = new Game();
        qDebug() << "Anzahl Steine im Beutel" << Game::beutelStackFarbe.size();

        QLabel *newIcon = new QLabel( );

        //qDebug() << undoClass::undoParent.top() ;
        newIcon->setParent( undoClass::undoParent.top() );
        newIcon->setPixmap( getPixmap( Game::beutelStackFarbe.back(), Game::beutelStackForm.back() ) );
        qDebug() << "Farbe und Form der Pixmap aus dem Beutel" << Game::beutelStackFarbe.back() << Game::beutelStackForm.back() << "Anzahl Steine im Beutel" << Game::beutelStackFarbe.size();
        if ((undoClass::undoCoordOldX.empty() == false) && (undoClass::undoCoordOldY.empty() == false))
            newIcon->move( undoClass::undoCoordOldX.top(), undoClass::undoCoordOldY.top() );
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        pframe2->updateFrames();

        /*******Stacks updaten***********************/
        Game::beutelStackForm.pop_back();
        Game::beutelStackFarbe.pop_back();
        Game::beutelStackKopie.pop_back();

        /***************kurze Prüfung für das Ende, das braucht den undo Stack*********************/

        //endcheck();

        undoClass::undoStack.pop();
        undoClass::undoParent.pop();
        undoClass::undoCoordOldX.pop();
        undoClass::undoCoordOldY.pop();
        undoClass::undoReihe.pop();
        undoClass::undoSpalte.pop();
        if( !undoClass::undoPixmap.empty() )
            undoClass::undoPixmap.pop();                                  // hier stürzt er ab, wenn man einen richtigen zug macht
                                                                      // dann richtige steine legt, dann einen falschen und dann abgeben will
    }

    /************* undo Funktion zurücksetzen *****************************/

    while( undoClass::undoStack.size() >0 )
    {
        qDebug() << "hier sollte er nicht sein, wenn nur ein faslcher zug gemacht wurde, und dann abgegeben";
        //undoClass::undoStack.pop();
        //undoClass::undoParent.pop();
        //undoClass::undoCoordOldX.pop();
        //undoClass::undoCoordOldY.pop();
        //undoClass::undoReihe.pop();
        //undoClass::undoSpalte.pop();
        //undoClass::undoPixmap.pop();
    }

    bewegteSteinej();

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


    //Beutel als Json speichern und versenden



    //TODO: Spielerstatus deaktivieren
    //ChatClient::sendMessage();

    SteinImFeld = 0;
    qDebug() << "ZugEnde, hier sollte wieder 0 stehen: " << SteinImFeld;
    qDebug() << "Anzahl formen im Beutel: " << Game::beutelStackForm.size() << "Anzahl farben im Beutel: " << Game::beutelStackFarbe.size();

    while( !Tauschen::getauschteSteine.empty() )
    {
        Tauschen::getauschteSteine.pop_back();
    }
    // QJsonArray array = { 1, 2, 2.3 ,QString("test")};
    //        m_chatClient->sendTurn(array);
    QString point = QString::number(spielerpunkte);
    m_chatClient->sendPoints(point);
    m_chatClient->nextPlayer();

    if(spielende==true)
    {
        //für den Spieler der zuletzt dran war, wird noch spielerpunkte = spielerpunkte + extrapunkte gerechnet
        //gewinnerEnde(int spielerpunkte1, spielerpunkte2, spielerpunkte3, spielerpunkte4);
    }

    pass = false;

    //QJsonArray form = json::toJson(beutelStackForm);
    //m_chatClient->sendForm(form);
    //QJsonArray farbe = json::toJson(beutelStackFarbe);
    //m_chatClient->sendFarbe(farbe);
    //QJsonArray kopie = json::toJson(beutelStackKopie);
    //m_chatClient->sendKopie(kopie);
    //QString point = QString::number(spielerpunkte);
    qDebug() << "*****************************Zugende**********************************";
}

/*
QString point = QString::number(spielerpunkte);
m_chatClient->sendPoints(point);
m_chatClient->nextPlayer();
*/

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
