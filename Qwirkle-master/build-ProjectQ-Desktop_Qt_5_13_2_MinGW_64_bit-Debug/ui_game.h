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
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLCDNumber *lcdNumber;
    QLabel *label_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    Tauschen *frame;
    QWidget *hand;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *lhand;
    QLineEdit *messageEdit;
    QListView *chatView;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *lfeld;
    QFrame *unten_links;
    QWidget *hand1;
    QWidget *horizontalLayoutWidget1;
    QHBoxLayout *lhand1;
    QLCDNumber *lcdNumber1;
    QLabel *label1;
    QLabel *label_21;
    QPushButton *pushButton_21;
    QPushButton *einstellungen;
    QPushButton *pushButton_41;
    QFrame *unten_mitte;
    QListView *chatView1;
    QLineEdit *messageEdit1;
    QFrame *unten_rechts;
    Tauschen *frame1;
    QPushButton *pushButton_61;
    QPushButton *pushButton_71;
    QLabel *label_3;
    QPushButton *pushButton1;

    void setupUi(QWidget *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(1508, 803);
        Game->setAutoFillBackground(false);
        pushButton = new QPushButton(Game);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1340, 760, 161, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Candara Light"));
        font.setPointSize(18);
        pushButton->setFont(font);
        label = new QLabel(Game);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 710, 351, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Candara Light"));
        font1.setPointSize(11);
        label->setFont(font1);
        pushButton_2 = new QPushButton(Game);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 760, 101, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Candara Light"));
        font2.setPointSize(16);
        pushButton_2->setFont(font2);
        pushButton_3 = new QPushButton(Game);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 760, 101, 41));
        pushButton_4 = new QPushButton(Game);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(250, 760, 101, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Candara Light"));
        font3.setPointSize(12);
        pushButton_4->setFont(font3);
        lcdNumber = new QLCDNumber(Game);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(360, 720, 261, 41));
        label_2 = new QLabel(Game);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 770, 151, 21));
        label_2->setFont(font2);
        pushButton_6 = new QPushButton(Game);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(1170, 650, 81, 71));
        pushButton_7 = new QPushButton(Game);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(1270, 650, 81, 71));
        frame = new Tauschen(Game);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(1070, 650, 81, 71));
        frame->setAcceptDrops(true);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 158, 158);"));
        hand = new QWidget(Game);
        hand->setObjectName(QString::fromUtf8("hand"));
        hand->setGeometry(QRect(9, 639, 621, 71));
        hand->setAcceptDrops(true);
        hand->setToolTipDuration(-1);
        horizontalLayoutWidget = new QWidget(hand);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 621, 71));
        lhand = new QHBoxLayout(horizontalLayoutWidget);
        lhand->setObjectName(QString::fromUtf8("lhand"));
        lhand->setSizeConstraint(QLayout::SetMaximumSize);
        lhand->setContentsMargins(0, 0, 0, 0);
        messageEdit = new QLineEdit(Game);
        messageEdit->setObjectName(QString::fromUtf8("messageEdit"));
        messageEdit->setGeometry(QRect(640, 760, 411, 27));
        chatView = new QListView(Game);
        chatView->setObjectName(QString::fromUtf8("chatView"));
        chatView->setGeometry(QRect(640, 640, 411, 121));
        scrollArea = new QScrollArea(Game);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 1491, 621));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setAutoFillBackground(false);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1462, 592));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 1471, 601));
        lfeld = new QGridLayout(gridLayoutWidget);
        lfeld->setSpacing(0);
        lfeld->setObjectName(QString::fromUtf8("lfeld"));
        lfeld->setSizeConstraint(QLayout::SetMinAndMaxSize);
        lfeld->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);
        unten_links = new QFrame(Game);
        unten_links->setObjectName(QString::fromUtf8("unten_links"));
        unten_links->setGeometry(QRect(0, 640, 641, 161));
        unten_links->setMinimumSize(QSize(641, 161));
        unten_links->setFrameShape(QFrame::StyledPanel);
        unten_links->setFrameShadow(QFrame::Raised);
        hand1 = new QWidget(unten_links);
        hand1->setObjectName(QString::fromUtf8("hand1"));
        hand1->setGeometry(QRect(10, 0, 621, 71));
        hand1->setAcceptDrops(true);
        hand1->setToolTipDuration(-1);
        horizontalLayoutWidget1 = new QWidget(hand1);
        horizontalLayoutWidget1->setObjectName(QString::fromUtf8("horizontalLayoutWidget1"));
        horizontalLayoutWidget1->setGeometry(QRect(0, 0, 621, 71));
        lhand1 = new QHBoxLayout(horizontalLayoutWidget1);
        lhand1->setObjectName(QString::fromUtf8("lhand1"));
        lhand1->setSizeConstraint(QLayout::SetMaximumSize);
        lhand1->setContentsMargins(0, 0, 0, 0);
        lcdNumber1 = new QLCDNumber(unten_links);
        lcdNumber1->setObjectName(QString::fromUtf8("lcdNumber1"));
        lcdNumber1->setGeometry(QRect(360, 80, 261, 41));
        label1 = new QLabel(unten_links);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(10, 70, 351, 21));
        label1->setFont(font1);
        label_21 = new QLabel(unten_links);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(370, 130, 151, 21));
        label_21->setFont(font2);
        pushButton_21 = new QPushButton(unten_links);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        pushButton_21->setGeometry(QRect(10, 110, 101, 41));
        pushButton_21->setFont(font2);
        einstellungen = new QPushButton(unten_links);
        einstellungen->setObjectName(QString::fromUtf8("einstellungen"));
        einstellungen->setGeometry(QRect(130, 110, 101, 41));
        pushButton_41 = new QPushButton(unten_links);
        pushButton_41->setObjectName(QString::fromUtf8("pushButton_41"));
        pushButton_41->setGeometry(QRect(240, 110, 101, 41));
        pushButton_41->setFont(font3);
        unten_mitte = new QFrame(Game);
        unten_mitte->setObjectName(QString::fromUtf8("unten_mitte"));
        unten_mitte->setGeometry(QRect(649, 639, 411, 161));
        unten_mitte->setMinimumSize(QSize(411, 161));
        unten_mitte->setFrameShape(QFrame::StyledPanel);
        unten_mitte->setFrameShadow(QFrame::Raised);
        chatView1 = new QListView(unten_mitte);
        chatView1->setObjectName(QString::fromUtf8("chatView1"));
        chatView1->setGeometry(QRect(0, 0, 411, 131));
        messageEdit1 = new QLineEdit(unten_mitte);
        messageEdit1->setObjectName(QString::fromUtf8("messageEdit1"));
        messageEdit1->setGeometry(QRect(0, 130, 411, 27));
        unten_rechts = new QFrame(Game);
        unten_rechts->setObjectName(QString::fromUtf8("unten_rechts"));
        unten_rechts->setGeometry(QRect(1070, 640, 431, 161));
        unten_rechts->setMinimumSize(QSize(431, 161));
        unten_rechts->setFrameShape(QFrame::StyledPanel);
        unten_rechts->setFrameShadow(QFrame::Raised);
        frame1 = new Tauschen(unten_rechts);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setGeometry(QRect(20, 0, 81, 71));
        frame1->setAcceptDrops(true);
        frame1->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 158, 158);"));
        frame1->setFrameShape(QFrame::Box);
        frame1->setFrameShadow(QFrame::Sunken);
        pushButton_61 = new QPushButton(unten_rechts);
        pushButton_61->setObjectName(QString::fromUtf8("pushButton_61"));
        pushButton_61->setGeometry(QRect(150, 0, 81, 71));
        pushButton_71 = new QPushButton(unten_rechts);
        pushButton_71->setObjectName(QString::fromUtf8("pushButton_71"));
        pushButton_71->setGeometry(QRect(280, 0, 81, 71));
        label_3 = new QLabel(unten_rechts);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 70, 91, 21));
        label_3->setFont(font3);
        pushButton1 = new QPushButton(unten_rechts);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
        pushButton1->setGeometry(QRect(290, 120, 131, 31));
        pushButton1->setFont(font);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QWidget *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Qwirkel", nullptr));
        pushButton->setText(QCoreApplication::translate("Game", "Beenden", nullptr));
        label->setText(QCoreApplication::translate("Game", "Benutzerhand", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Game", "Regeln", nullptr));
        pushButton_3->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("Game", "New Game", nullptr));
        label_2->setText(QCoreApplication::translate("Game", "Punktestand", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Game", "Undo", nullptr));
        pushButton_7->setText(QString());
        label1->setText(QCoreApplication::translate("Game", "Benutzerhand", nullptr));
        label_21->setText(QCoreApplication::translate("Game", "Punktestand", nullptr));
        pushButton_21->setText(QCoreApplication::translate("Game", "Regeln", nullptr));
        einstellungen->setText(QString());
        pushButton_41->setText(QCoreApplication::translate("Game", "New Game", nullptr));
        pushButton_61->setText(QCoreApplication::translate("Game", "Undo", nullptr));
        pushButton_71->setText(QString());
        label_3->setText(QCoreApplication::translate("Game", "tauschen", nullptr));
        pushButton1->setText(QCoreApplication::translate("Game", "Beenden", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
