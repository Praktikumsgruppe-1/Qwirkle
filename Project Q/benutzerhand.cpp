/**********************************************************************/
// Datei: benutzerhand.cpp
// Die Klasse Benutzerhand beinhaltet das QFrame, welches die kleinen
// Spielsteine auf der Benutzerhand darstellt und die Drag and Drop
// Funktionen enthält um sie zu bewegen
/**********************************************************************/

#include <QtWidgets>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QFrame>
#include <QPicture>
#include <QPixmap>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <string>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QRandomGenerator>
#include <qglobal.h>
#include <QTime>

#include "benutzerhand.h"
#include "undo.h"


// Konstruktor
Benutzerhand::Benutzerhand(QWidget *parent, int a, int b)
    : QFrame(parent)
{
    setMinimumSize(20, 20);
    setFrameStyle(QFrame::Raised | QFrame::Box);
    setAcceptDrops(true);

    QLabel *stein1Icon = new QLabel(this);
    stein1Icon->setPixmap( getPixmap( a, b) );
    //stein1Icon->move(2, 2);
    stein1Icon->setScaledContents(true);
    stein1Icon->show();
    stein1Icon->setAttribute(Qt::WA_DeleteOnClose);
}


/*********** Drag and Drop Funktionen *************************************************/

void Benutzerhand::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Benutzerhand::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Benutzerhand::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if (!child)
        return;

    QPixmap pixmap = *child->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - child->pos());

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());

    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    child->setPixmap(tempPixmap);

    undoClass::undoParent.push( this );
    undoClass::undoCoordOldX.push( child->geometry().x() );
    undoClass::undoCoordOldY.push( child->geometry().y() );
    undoClass::undoPixmap.push( *(child->pixmap()) );
    qDebug() << "mousepressEvent" << getFormPixmap( *(child->pixmap()) ) << getFarbePixmap( *(child->pixmap()) );


    if (drag->exec(Qt::MoveAction) == Qt::MoveAction)
    {
        qDebug("hier bin ich wenn ich richtig gedroppt habe");
        child->close();
    }

    else
    {
        child->close();
        //child->setPixmap(pixmap);
        qDebug("hier bin ich, wenn ich gedroppt habe");
    }

}

/************ Funktionen ************************************************************/

//die extern definierte Funktion zum randomizen der Stein_Zahlen für das Benutzerhand
extern int randInt(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}


// liefert ein Pixmap zu zwei Indizes zurück
extern QPixmap getPixmap( int a, int b )
{
    QPixmap blau_eckig (QPixmap(":/images/blau_eckig2.svg"));
    QPixmap blau_kreuz (QPixmap(":/images/blau_kreuz1.svg"));
    QPixmap blau_raute (QPixmap(":/images/blau_raute1.svg"));
    QPixmap blau_rund (QPixmap(":/images/blau_rund1.svg"));
    QPixmap blau_sonne (QPixmap(":/images/blau_sonne1.svg"));
    QPixmap blau_stern (QPixmap(":/images/blau_stern1.svg"));

    QPixmap gelb_eckig (QPixmap(":/images/gelb_eckig1.svg"));
    QPixmap gelb_kreuz (QPixmap(":/images/gelb_kreuz1.svg"));
    QPixmap gelb_raute (QPixmap(":/images/gelb_raute1.svg"));
    QPixmap gelb_rund (QPixmap(":/images/gelb_rund1.svg"));
    QPixmap gelb_sonne (QPixmap(":/images/gelb_sonne1.svg"));
    QPixmap gelb_stern (QPixmap(":/images/gelb_stern1.svg"));

    QPixmap gruen_eckig (QPixmap(":/images/gruen_eckig1.svg"));
    QPixmap gruen_kreuz (QPixmap(":/images/gruen_kreuz1.svg"));
    QPixmap gruen_raute (QPixmap(":/images/gruen_raute1.svg"));
    QPixmap gruen_sonne (QPixmap(":/images/gruen_sonne1.svg"));
    QPixmap gruen_rund (QPixmap(":/images/gruen_rund1.svg"));
    QPixmap gruen_stern (QPixmap(":/images/gruen_stern1.svg"));

    QPixmap lila_eckig (QPixmap(":/images/lila_eckig1.svg"));
    QPixmap lila_kreuz (QPixmap(":/images/lila_kreuz1.svg"));
    QPixmap lila_raute (QPixmap(":/images/lila_raute1.svg"));
    QPixmap lila_rund (QPixmap(":/images/lila_rund1.svg"));
    QPixmap lila_sonne (QPixmap(":/images/lila_sonne1.svg"));
    QPixmap lila_stern (QPixmap(":/images/lila_stern1.svg"));

    QPixmap orange_eckig (QPixmap(":/images/orange_eckig1.svg"));
    QPixmap orange_kreuz (QPixmap(":/images/orange_kreuz1.svg"));
    QPixmap orange_raute (QPixmap(":/images/orange_raute1.svg"));
    QPixmap orange_rund (QPixmap(":/images/orange_rund1.svg"));
    QPixmap orange_sonne (QPixmap(":/images/orange_sonne1.svg"));
    QPixmap orange_stern (QPixmap(":/images/orange_stern1.svg"));

    QPixmap rot_eckig (QPixmap(":/images/rot_eckig1.svg"));
    QPixmap rot_kreuz (QPixmap(":/images/rot_kreuz1.svg"));
    QPixmap rot_raute (QPixmap(":/images/rot_raute1.svg"));
    QPixmap rot_rund (QPixmap(":/images/rot_rund1.svg"));
    QPixmap rot_sonne (QPixmap(":/images/rot_sonne1.svg"));
    QPixmap rot_stern (QPixmap(":/images/rot_stern1.svg"));

    QPixmap stein[6][6] =
    {
       {blau_eckig, blau_kreuz, blau_raute, blau_rund, blau_sonne, blau_stern},
       {gelb_eckig, gelb_kreuz, gelb_raute, gelb_rund, gelb_sonne, gelb_stern},
       {gruen_eckig, gruen_kreuz, gruen_raute, gruen_rund, gruen_sonne, gruen_stern},
       {lila_eckig, lila_kreuz, lila_raute, lila_rund, lila_sonne, lila_stern},
       {orange_eckig, orange_kreuz, orange_raute, orange_rund, orange_sonne, orange_stern},
       {rot_eckig, rot_kreuz, rot_raute, rot_rund, rot_sonne, rot_stern}
    };

    return QPixmap(stein[a][b]);
}


// liefert ersten Indize zu einem Pixmap zurück
extern int getFarbePixmap( QPixmap pixmap )
{
    // Definition der Pixmaps und zuordnung zu ihren Indizes
    qDebug("getFarbePixmap fängt an");
    QPixmap blau_eckig (QPixmap(":/images/blau_eckig2.svg"));
    QPixmap blau_kreuz (QPixmap(":/images/blau_kreuz1.svg"));
    QPixmap blau_raute (QPixmap(":/images/blau_raute1.svg"));
    QPixmap blau_rund (QPixmap(":/images/blau_rund1.svg"));
    QPixmap blau_sonne (QPixmap(":/images/blau_sonne1.svg"));
    QPixmap blau_stern (QPixmap(":/images/blau_stern1.svg"));

    QPixmap gelb_eckig (QPixmap(":/images/gelb_eckig1.svg"));
    QPixmap gelb_kreuz (QPixmap(":/images/gelb_kreuz1.svg"));
    QPixmap gelb_raute (QPixmap(":/images/gelb_raute1.svg"));
    QPixmap gelb_rund (QPixmap(":/images/gelb_rund1.svg"));
    QPixmap gelb_sonne (QPixmap(":/images/gelb_sonne1.svg"));
    QPixmap gelb_stern (QPixmap(":/images/gelb_stern1.svg"));

    QPixmap gruen_eckig (QPixmap(":/images/gruen_eckig1.svg"));
    QPixmap gruen_kreuz (QPixmap(":/images/gruen_kreuz1.svg"));
    QPixmap gruen_raute (QPixmap(":/images/gruen_raute1.svg"));
    QPixmap gruen_sonne (QPixmap(":/images/gruen_sonne1.svg"));
    QPixmap gruen_rund (QPixmap(":/images/gruen_rund1.svg"));
    QPixmap gruen_stern (QPixmap(":/images/gruen_stern1.svg"));

    QPixmap lila_eckig (QPixmap(":/images/lila_eckig1.svg"));
    QPixmap lila_kreuz (QPixmap(":/images/lila_kreuz1.svg"));
    QPixmap lila_raute (QPixmap(":/images/lila_raute1.svg"));
    QPixmap lila_rund (QPixmap(":/images/lila_rund1.svg"));
    QPixmap lila_sonne (QPixmap(":/images/lila_sonne1.svg"));
    QPixmap lila_stern (QPixmap(":/images/lila_stern1.svg"));

    QPixmap orange_eckig (QPixmap(":/images/orange_eckig1.svg"));
    QPixmap orange_kreuz (QPixmap(":/images/orange_kreuz1.svg"));
    QPixmap orange_raute (QPixmap(":/images/orange_raute1.svg"));
    QPixmap orange_rund (QPixmap(":/images/orange_rund1.svg"));
    QPixmap orange_sonne (QPixmap(":/images/orange_sonne1.svg"));
    QPixmap orange_stern (QPixmap(":/images/orange_stern1.svg"));

    QPixmap rot_eckig (QPixmap(":/images/rot_eckig1.svg"));
    QPixmap rot_kreuz (QPixmap(":/images/rot_kreuz1.svg"));
    QPixmap rot_raute (QPixmap(":/images/rot_raute1.svg"));
    QPixmap rot_rund (QPixmap(":/images/rot_rund1.svg"));
    QPixmap rot_sonne (QPixmap(":/images/rot_sonne1.svg"));
    QPixmap rot_stern (QPixmap(":/images/rot_stern1.svg"));

    QPixmap stein[6][6] =
    {
       {blau_eckig, blau_kreuz, blau_raute, blau_rund, blau_sonne, blau_stern},
       {gelb_eckig, gelb_kreuz, gelb_raute, gelb_rund, gelb_sonne, gelb_stern},
       {gruen_eckig, gruen_kreuz, gruen_raute, gruen_rund, gruen_sonne, gruen_stern},
       {lila_eckig, lila_kreuz, lila_raute, lila_rund, lila_sonne, lila_stern},
       {orange_eckig, orange_kreuz, orange_raute, orange_rund, orange_sonne, orange_stern},
       {rot_eckig, rot_kreuz, rot_raute, rot_rund, rot_sonne, rot_stern}
    };


    // Vergleich des übergebenen Pixmaps mit den gegebenen Pixmaps
    int i=0, j=0;
    bool pixmapsgleich = true;
    for( i = 0; (i < 6); i++ )
    {
        for( j = 0; j < 6; j++ )
        {
            for(int x = 0; x < 75; x++)
            {
                for(int y = 0; y < 75; y++)
                {
                    if ( stein[i][j].toImage().pixel(x, y) != ( pixmap.toImage().pixel(x , y) ) )
                    {
                        pixmapsgleich = false;
                    }
                }
            }
            if( pixmapsgleich == true )
                return i;
            pixmapsgleich = true;
        }
    }
}


// liefert zweiten Indize zu einem Pixmap zurück
extern int getFormPixmap( QPixmap pixmap )
{
    // Definition der Pixmaps und zuordnung zu ihren Indizes
    qDebug("getFormPixmap fängt an");
    QPixmap blau_eckig (QPixmap(":/images/blau_eckig2.svg"));
    QPixmap blau_kreuz (QPixmap(":/images/blau_kreuz1.svg"));
    QPixmap blau_raute (QPixmap(":/images/blau_raute1.svg"));
    QPixmap blau_rund (QPixmap(":/images/blau_rund1.svg"));
    QPixmap blau_sonne (QPixmap(":/images/blau_sonne1.svg"));
    QPixmap blau_stern (QPixmap(":/images/blau_stern1.svg"));

    QPixmap gelb_eckig (QPixmap(":/images/gelb_eckig1.svg"));
    QPixmap gelb_kreuz (QPixmap(":/images/gelb_kreuz1.svg"));
    QPixmap gelb_raute (QPixmap(":/images/gelb_raute1.svg"));
    QPixmap gelb_rund (QPixmap(":/images/gelb_rund1.svg"));
    QPixmap gelb_sonne (QPixmap(":/images/gelb_sonne1.svg"));
    QPixmap gelb_stern (QPixmap(":/images/gelb_stern1.svg"));

    QPixmap gruen_eckig (QPixmap(":/images/gruen_eckig1.svg"));
    QPixmap gruen_kreuz (QPixmap(":/images/gruen_kreuz1.svg"));
    QPixmap gruen_raute (QPixmap(":/images/gruen_raute1.svg"));
    QPixmap gruen_sonne (QPixmap(":/images/gruen_sonne1.svg"));
    QPixmap gruen_rund (QPixmap(":/images/gruen_rund1.svg"));
    QPixmap gruen_stern (QPixmap(":/images/gruen_stern1.svg"));

    QPixmap lila_eckig (QPixmap(":/images/lila_eckig1.svg"));
    QPixmap lila_kreuz (QPixmap(":/images/lila_kreuz1.svg"));
    QPixmap lila_raute (QPixmap(":/images/lila_raute1.svg"));
    QPixmap lila_rund (QPixmap(":/images/lila_rund1.svg"));
    QPixmap lila_sonne (QPixmap(":/images/lila_sonne1.svg"));
    QPixmap lila_stern (QPixmap(":/images/lila_stern1.svg"));

    QPixmap orange_eckig (QPixmap(":/images/orange_eckig1.svg"));
    QPixmap orange_kreuz (QPixmap(":/images/orange_kreuz1.svg"));
    QPixmap orange_raute (QPixmap(":/images/orange_raute1.svg"));
    QPixmap orange_rund (QPixmap(":/images/orange_rund1.svg"));
    QPixmap orange_sonne (QPixmap(":/images/orange_sonne1.svg"));
    QPixmap orange_stern (QPixmap(":/images/orange_stern1.svg"));

    QPixmap rot_eckig (QPixmap(":/images/rot_eckig1.svg"));
    QPixmap rot_kreuz (QPixmap(":/images/rot_kreuz1.svg"));
    QPixmap rot_raute (QPixmap(":/images/rot_raute1.svg"));
    QPixmap rot_rund (QPixmap(":/images/rot_rund1.svg"));
    QPixmap rot_sonne (QPixmap(":/images/rot_sonne1.svg"));
    QPixmap rot_stern (QPixmap(":/images/rot_stern1.svg"));

    QPixmap stein[6][6] =
    {
       {blau_eckig, blau_kreuz, blau_raute, blau_rund, blau_sonne, blau_stern},
       {gelb_eckig, gelb_kreuz, gelb_raute, gelb_rund, gelb_sonne, gelb_stern},
       {gruen_eckig, gruen_kreuz, gruen_raute, gruen_rund, gruen_sonne, gruen_stern},
       {lila_eckig, lila_kreuz, lila_raute, lila_rund, lila_sonne, lila_stern},
       {orange_eckig, orange_kreuz, orange_raute, orange_rund, orange_sonne, orange_stern},
       {rot_eckig, rot_kreuz, rot_raute, rot_rund, rot_sonne, rot_stern}
    };


    // Vergleich des übergebenen Pixmaps mit den gegebenen Pixmaps
    int i=0, j=0;
    bool pixmapsgleich = true;
    for( i = 0; (i < 6); i++ )
    {
        for( j = 0; j < 6; j++ )
        {
            for(int x = 0; x < 75; x++)
            {
                for(int y = 0; y < 75; y++)
                {
                    if ( stein[i][j].toImage().pixel(x, y) != ( pixmap.toImage().pixel(x , y) ) )
                    {
                        pixmapsgleich = false;
                    }
                }
            }
            if( pixmapsgleich == true )
                return j;
            pixmapsgleich = true;
        }
    }
}
