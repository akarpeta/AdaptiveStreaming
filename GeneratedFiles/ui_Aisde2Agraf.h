/********************************************************************************
** Form generated from reading UI file 'Aisde2Agraf.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AISDE2AGRAF_H
#define UI_AISDE2AGRAF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Aisde2AgrafClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QCustomPlot *customplot;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Aisde2AgrafClass)
    {
        if (Aisde2AgrafClass->objectName().isEmpty())
            Aisde2AgrafClass->setObjectName(QStringLiteral("Aisde2AgrafClass"));
        Aisde2AgrafClass->resize(1072, 837);
        centralWidget = new QWidget(Aisde2AgrafClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 121, 28));
        customplot = new QCustomPlot(centralWidget);
        customplot->setObjectName(QStringLiteral("customplot"));
        customplot->setGeometry(QRect(160, 10, 881, 751));
        Aisde2AgrafClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Aisde2AgrafClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1072, 26));
        Aisde2AgrafClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Aisde2AgrafClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Aisde2AgrafClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Aisde2AgrafClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Aisde2AgrafClass->setStatusBar(statusBar);

        retranslateUi(Aisde2AgrafClass);
        QObject::connect(pushButton, SIGNAL(clicked()), Aisde2AgrafClass, SLOT(startSimulation()));
        QObject::connect(pushButton, SIGNAL(clicked()), Aisde2AgrafClass, SLOT(drawGraph()));

        QMetaObject::connectSlotsByName(Aisde2AgrafClass);
    } // setupUi

    void retranslateUi(QMainWindow *Aisde2AgrafClass)
    {
        Aisde2AgrafClass->setWindowTitle(QApplication::translate("Aisde2AgrafClass", "Aisde2Agraf", nullptr));
        pushButton->setText(QApplication::translate("Aisde2AgrafClass", "Start Symulacji", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Aisde2AgrafClass: public Ui_Aisde2AgrafClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AISDE2AGRAF_H
