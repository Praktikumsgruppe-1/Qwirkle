/********************************************************************************
** Form generated from reading UI file 'einstellungen.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EINSTELLUNGEN_H
#define UI_EINSTELLUNGEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Einstellungen
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Einstellungen)
    {
        if (Einstellungen->objectName().isEmpty())
            Einstellungen->setObjectName(QString::fromUtf8("Einstellungen"));
        Einstellungen->resize(1143, 708);
        pushButton = new QPushButton(Einstellungen);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 131, 31));
        pushButton_2 = new QPushButton(Einstellungen);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 60, 131, 31));
        widget = new QWidget(Einstellungen);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(170, 20, 951, 631));
        pushButton_3 = new QPushButton(Einstellungen);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(1040, 660, 91, 30));

        retranslateUi(Einstellungen);

        QMetaObject::connectSlotsByName(Einstellungen);
    } // setupUi

    void retranslateUi(QWidget *Einstellungen)
    {
        Einstellungen->setWindowTitle(QCoreApplication::translate("Einstellungen", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Einstellungen", "Einstellungen", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Einstellungen", "About", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Einstellungen", "Beenden", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Einstellungen: public Ui_Einstellungen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EINSTELLUNGEN_H
