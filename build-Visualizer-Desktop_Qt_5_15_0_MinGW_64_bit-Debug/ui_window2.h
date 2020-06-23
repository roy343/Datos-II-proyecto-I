/********************************************************************************
** Form generated from reading UI file 'window2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW2_H
#define UI_WINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Window2
{
public:
    QPushButton *b1;
    QPushButton *b2;
    QListWidget *lista;

    void setupUi(QDialog *Window2)
    {
        if (Window2->objectName().isEmpty())
            Window2->setObjectName(QString::fromUtf8("Window2"));
        Window2->resize(297, 417);
        b1 = new QPushButton(Window2);
        b1->setObjectName(QString::fromUtf8("b1"));
        b1->setGeometry(QRect(30, 380, 93, 28));
        b2 = new QPushButton(Window2);
        b2->setObjectName(QString::fromUtf8("b2"));
        b2->setGeometry(QRect(180, 380, 93, 28));
        lista = new QListWidget(Window2);
        lista->setObjectName(QString::fromUtf8("lista"));
        lista->setGeometry(QRect(10, 10, 281, 361));

        retranslateUi(Window2);

        QMetaObject::connectSlotsByName(Window2);
    } // setupUi

    void retranslateUi(QDialog *Window2)
    {
        Window2->setWindowTitle(QCoreApplication::translate("Window2", "Dialog", nullptr));
        b1->setText(QCoreApplication::translate("Window2", "Actualizar", nullptr));
        b2->setText(QCoreApplication::translate("Window2", "Cerrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window2: public Ui_Window2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW2_H
