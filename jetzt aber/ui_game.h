/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>
#include <tauschen.h>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *lfeld;
    QFrame *unten_links;
    QWidget *hand;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *lhand;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *einstellungen;
    QPushButton *pushButton_4;
    QFrame *unten_mitte;
    QListView *chatView;
    QLineEdit *messageEdit;
    QFrame *unten_rechts;
    Tauschen *frame;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QWidget *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(1508, 803);
        Game->setAutoFillBackground(false);
        scrollArea = new QScrollArea(Game);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 1491, 621));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(1491, 621));
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setLineWidth(2);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1469, 599));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 1471, 601));
        lfeld = new QGridLayout(gridLayoutWidget);
        lfeld->setSpacing(0);
        lfeld->setObjectName(QString::fromUtf8("lfeld"));
        lfeld->setSizeConstraint(QLayout::SetMinimumSize);
        lfeld->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);
        unten_links = new QFrame(Game);
        unten_links->setObjectName(QString::fromUtf8("unten_links"));
        unten_links->setGeometry(QRect(0, 640, 641, 161));
        unten_links->setMinimumSize(QSize(641, 161));
        unten_links->setFrameShape(QFrame::StyledPanel);
        unten_links->setFrameShadow(QFrame::Raised);
        hand = new QWidget(unten_links);
        hand->setObjectName(QString::fromUtf8("hand"));
        hand->setGeometry(QRect(10, 0, 621, 71));
        hand->setAcceptDrops(true);
        hand->setToolTipDuration(-1);
        horizontalLayoutWidget = new QWidget(hand);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 621, 71));
        lhand = new QHBoxLayout(horizontalLayoutWidget);
        lhand->setObjectName(QString::fromUtf8("lhand"));
        lhand->setSizeConstraint(QLayout::SetMaximumSize);
        lhand->setContentsMargins(0, 0, 0, 0);
        lcdNumber = new QLCDNumber(unten_links);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(360, 80, 261, 41));
        label = new QLabel(unten_links);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 70, 351, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Candara Light"));
        font.setPointSize(11);
        label->setFont(font);
        label_2 = new QLabel(unten_links);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 130, 151, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Candara Light"));
        font1.setPointSize(16);
        label_2->setFont(font1);
        pushButton_2 = new QPushButton(unten_links);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 110, 101, 41));
        pushButton_2->setFont(font1);
        einstellungen = new QPushButton(unten_links);
        einstellungen->setObjectName(QString::fromUtf8("einstellungen"));
        einstellungen->setGeometry(QRect(130, 110, 101, 41));
        pushButton_4 = new QPushButton(unten_links);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(240, 110, 101, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Candara Light"));
        font2.setPointSize(12);
        pushButton_4->setFont(font2);
        unten_mitte = new QFrame(Game);
        unten_mitte->setObjectName(QString::fromUtf8("unten_mitte"));
        unten_mitte->setGeometry(QRect(649, 639, 521, 161));
        unten_mitte->setMinimumSize(QSize(521, 161));
        unten_mitte->setFrameShape(QFrame::StyledPanel);
        unten_mitte->setFrameShadow(QFrame::Raised);
        chatView = new QListView(unten_mitte);
        chatView->setObjectName(QString::fromUtf8("chatView"));
        chatView->setGeometry(QRect(0, 0, 521, 131));
        chatView->setMinimumSize(QSize(521, 131));
        messageEdit = new QLineEdit(unten_mitte);
        messageEdit->setObjectName(QString::fromUtf8("messageEdit"));
        messageEdit->setGeometry(QRect(0, 130, 521, 27));
        messageEdit->setMinimumSize(QSize(521, 27));
        unten_rechts = new QFrame(Game);
        unten_rechts->setObjectName(QString::fromUtf8("unten_rechts"));
        unten_rechts->setGeometry(QRect(1180, 640, 321, 161));
        unten_rechts->setMinimumSize(QSize(321, 161));
        unten_rechts->setFrameShape(QFrame::StyledPanel);
        unten_rechts->setFrameShadow(QFrame::Raised);
        frame = new Tauschen(unten_rechts);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 0, 81, 71));
        frame->setAcceptDrops(true);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 158, 158);"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        pushButton_6 = new QPushButton(unten_rechts);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(120, 0, 81, 71));
        pushButton_7 = new QPushButton(unten_rechts);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(220, 0, 81, 71));
        label_3 = new QLabel(unten_rechts);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 70, 91, 21));
        label_3->setFont(font2);
        pushButton = new QPushButton(unten_rechts);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 120, 131, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Candara Light"));
        font3.setPointSize(18);
        pushButton->setFont(font3);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QWidget *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Qwirkel", nullptr));
        label->setText(QCoreApplication::translate("Game", "Benutzerhand", nullptr));
        label_2->setText(QCoreApplication::translate("Game", "Punktestand", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Game", "Regeln", nullptr));
        einstellungen->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("Game", "New Game", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Game", "Undo", nullptr));
        pushButton_7->setText(QString());
        label_3->setText(QCoreApplication::translate("Game", "tauschen", nullptr));
        pushButton->setText(QCoreApplication::translate("Game", "Beenden", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
