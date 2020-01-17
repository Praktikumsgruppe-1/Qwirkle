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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <spielfeld.h>
#include <tauschen.h>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QPushButton *pushButton;
    Spielfeld *frame;
    QLabel *label;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLCDNumber *lcdNumber;
    QLabel *label_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    Tauschen *frame1;
    QWidget *hand;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *lhand;

    void setupUi(QWidget *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(1508, 803);
        pushButton = new QPushButton(Game);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1370, 770, 131, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Candara Light"));
        font.setPointSize(18);
        pushButton->setFont(font);
        frame = new Spielfeld(Game);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 1491, 621));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(3);
        label = new QLabel(Game);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 710, 351, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Candara Light"));
        font1.setPointSize(11);
        label->setFont(font1);
        textBrowser = new QTextBrowser(Game);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(640, 640, 411, 121));
        textEdit = new QTextEdit(Game);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(640, 760, 411, 41));
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
        frame1 = new Tauschen(Game);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setGeometry(QRect(1070, 650, 81, 71));
        frame1->setAcceptDrops(true);
        frame1->setStyleSheet(QString::fromUtf8("background-color: rgb(158, 158, 158);"));
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

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QWidget *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Game", "Beenden", nullptr));
        label->setText(QCoreApplication::translate("Game", "Benutzerhand", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Game", "Regeln", nullptr));
        pushButton_3->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("Game", "New Game", nullptr));
        label_2->setText(QCoreApplication::translate("Game", "Punktestand", nullptr));
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
