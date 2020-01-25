/********************************************************************************
** Form generated from reading UI file 'ruleswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULESWINDOW_H
#define UI_RULESWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rulesWindow
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *lregel;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *rulesWindow)
    {
        if (rulesWindow->objectName().isEmpty())
            rulesWindow->setObjectName(QString::fromUtf8("rulesWindow"));
        rulesWindow->resize(840, 865);
        rulesWindow->setMinimumSize(QSize(840, 865));
        scrollArea = new QScrollArea(rulesWindow);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(-1, -1, 841, 831));
        scrollArea->setMinimumSize(QSize(841, 831));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 839, 829));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContents);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -1, 841, 2399));
        lregel = new QVBoxLayout(verticalLayoutWidget);
        lregel->setObjectName(QString::fromUtf8("lregel"));
        lregel->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(839, 795));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/rulesImages/Spielanleitung_Qwirkle_1.PNG")));

        lregel->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(839, 795));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/rulesImages/Spielanleitung_Qwirkle_2.PNG")));

        lregel->addWidget(label_3);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(839, 795));
        label->setPixmap(QPixmap(QString::fromUtf8(":/rulesImages/Spielanleitung_Qwirkle_3.PNG")));

        lregel->addWidget(label);

        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton = new QPushButton(rulesWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(720, 830, 111, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Candara Light"));
        font.setPointSize(18);
        pushButton->setFont(font);

        retranslateUi(rulesWindow);

        QMetaObject::connectSlotsByName(rulesWindow);
    } // setupUi

    void retranslateUi(QWidget *rulesWindow)
    {
        rulesWindow->setWindowTitle(QCoreApplication::translate("rulesWindow", "Regeln", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("rulesWindow", "Beenden", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rulesWindow: public Ui_rulesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULESWINDOW_H
