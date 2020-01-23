/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
    QPushButton *einstellungen;
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
    QLabel *label_4;
    QLabel *label_3;

    void setupUi(QWidget *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(1508, 803);
        Game->setAutoFillBackground(false);
        pushButton = new QPushButton(Game);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1370, 770, 131, 31));
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
        einstellungen = new QPushButton(Game);
        einstellungen->setObjectName(QString::fromUtf8("einstellungen"));
        einstellungen->setGeometry(QRect(130, 760, 101, 41));
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
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
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
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
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
        lfeld->setSizeConstraint(QLayout::SetMinimumSize);
        lfeld->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(-6, -5, 1491, 621));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/hintergrund.jpg")));
        label_4->setScaledContents(true);
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_4->raise();
        gridLayoutWidget->raise();
        label_3 = new QLabel(Game);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1070, 720, 91, 21));
        label_3->setFont(font3);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QWidget *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Game", "Beenden", nullptr));
        label->setText(QCoreApplication::translate("Game", "Benutzerhand", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Game", "Regeln", nullptr));
        einstellungen->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("Game", "New Game", nullptr));
        label_2->setText(QCoreApplication::translate("Game", "Punktestand", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Game", "Undo", nullptr));
        pushButton_7->setText(QString());
        label_4->setText(QString());
        label_3->setText(QCoreApplication::translate("Game", "tauschen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
