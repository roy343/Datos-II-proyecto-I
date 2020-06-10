/********************************************************************************
** Form generated from reading UI file 'visualizer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALIZER_H
#define UI_VISUALIZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Visualizer
{
public:
    QWidget *centralwidget;
    QPushButton *b1;
    QPushButton *b2;
    QListWidget *lista;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Visualizer)
    {
        if (Visualizer->objectName().isEmpty())
            Visualizer->setObjectName(QString::fromUtf8("Visualizer"));
        Visualizer->resize(461, 566);
        centralwidget = new QWidget(Visualizer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        b1 = new QPushButton(centralwidget);
        b1->setObjectName(QString::fromUtf8("b1"));
        b1->setGeometry(QRect(10, 70, 93, 28));
        b2 = new QPushButton(centralwidget);
        b2->setObjectName(QString::fromUtf8("b2"));
        b2->setGeometry(QRect(10, 170, 93, 28));
        lista = new QListWidget(centralwidget);
        lista->setObjectName(QString::fromUtf8("lista"));
        lista->setGeometry(QRect(110, 10, 341, 481));
        Visualizer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Visualizer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 461, 26));
        Visualizer->setMenuBar(menubar);
        statusbar = new QStatusBar(Visualizer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Visualizer->setStatusBar(statusbar);

        retranslateUi(Visualizer);

        QMetaObject::connectSlotsByName(Visualizer);
    } // setupUi

    void retranslateUi(QMainWindow *Visualizer)
    {
        Visualizer->setWindowTitle(QCoreApplication::translate("Visualizer", "Visualizer", nullptr));
        b1->setText(QCoreApplication::translate("Visualizer", "Server", nullptr));
        b2->setText(QCoreApplication::translate("Visualizer", "Local", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Visualizer: public Ui_Visualizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZER_H
