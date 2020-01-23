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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rulesWindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *rulesWindow)
    {
        if (rulesWindow->objectName().isEmpty())
            rulesWindow->setObjectName(QString::fromUtf8("rulesWindow"));
        rulesWindow->resize(840, 865);
        rulesWindow->setMinimumSize(QSize(840, 865));
        layoutWidget = new QWidget(rulesWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 822, 846));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(layoutWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(820, 795));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(738, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(rulesWindow);

        QMetaObject::connectSlotsByName(rulesWindow);
    } // setupUi

    void retranslateUi(QWidget *rulesWindow)
    {
        rulesWindow->setWindowTitle(QCoreApplication::translate("rulesWindow", "Form", nullptr));
#if QT_CONFIG(tooltip)
        graphicsView->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QCoreApplication::translate("rulesWindow", "Beenden", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rulesWindow: public Ui_rulesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULESWINDOW_H
