/********************************************************************************
** Form generated from reading UI file 'lobbyerst.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOBBYERST_H
#define UI_LOBBYERST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LobbyErst
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QFrame *frame;

    void setupUi(QWidget *LobbyErst)
    {
        if (LobbyErst->objectName().isEmpty())
            LobbyErst->setObjectName(QString::fromUtf8("LobbyErst"));
        LobbyErst->resize(740, 605);
        pushButton = new QPushButton(LobbyErst);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 30, 701, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Candara Light"));
        font.setPointSize(28);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(LobbyErst);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 130, 701, 51));
        pushButton_2->setFont(font);
        frame = new QFrame(LobbyErst);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 280, 701, 311));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        retranslateUi(LobbyErst);

        QMetaObject::connectSlotsByName(LobbyErst);
    } // setupUi

    void retranslateUi(QWidget *LobbyErst)
    {
        LobbyErst->setWindowTitle(QCoreApplication::translate("LobbyErst", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("LobbyErst", "Spiel starten", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LobbyErst", "Spieler einladen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LobbyErst: public Ui_LobbyErst {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOBBYERST_H
