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
#include <benutzerhand.h>
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
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *hand;
    Benutzerhand *frame_7;
    Benutzerhand *frame_6;
    Benutzerhand *frame_5;
    Benutzerhand *frame_4;
    Benutzerhand *frame_3;
    Benutzerhand *frame_2;
    Tauschen *frame1;

    void setupUi(QWidget *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(1508, 803);
        pushButton = new QPushButton(Game);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1390, 770, 111, 31));
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
        label->setGeometry(QRect(10, 700, 351, 21));
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
        font3.setPointSize(14);
        pushButton_4->setFont(font3);
        lcdNumber = new QLCDNumber(Game);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(360, 720, 261, 41));
        label_2 = new QLabel(Game);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 770, 131, 21));
        label_2->setFont(font2);
        pushButton_6 = new QPushButton(Game);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(1170, 650, 81, 71));
        pushButton_7 = new QPushButton(Game);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(1270, 650, 81, 71));
        horizontalLayoutWidget = new QWidget(Game);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 640, 601, 61));
        hand = new QHBoxLayout(horizontalLayoutWidget);
        hand->setObjectName(QString::fromUtf8("hand"));
        hand->setContentsMargins(0, 0, 0, 0);
        frame_7 = new Benutzerhand(horizontalLayoutWidget);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);

        hand->addWidget(frame_7);

        frame_6 = new Benutzerhand(horizontalLayoutWidget);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);

        hand->addWidget(frame_6);

        frame_5 = new Benutzerhand(horizontalLayoutWidget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);

        hand->addWidget(frame_5);

        frame_4 = new Benutzerhand(horizontalLayoutWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);

        hand->addWidget(frame_4);

        frame_3 = new Benutzerhand(horizontalLayoutWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);

        hand->addWidget(frame_3);

        frame_2 = new Benutzerhand(horizontalLayoutWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        hand->addWidget(frame_2);

        frame1 = new Tauschen(Game);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setGeometry(QRect(1070, 650, 81, 71));
        frame1->setAcceptDrops(true);
        frame1->setStyleSheet(QString::fromUtf8("background-color: rgb(162, 162, 162);"));

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
        pushButton_6->setText(QCoreApplication::translate("Game", "Undo", nullptr));
        pushButton_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
