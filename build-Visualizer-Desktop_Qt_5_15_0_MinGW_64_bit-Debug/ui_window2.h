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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Window2
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Window2)
    {
        if (Window2->objectName().isEmpty())
            Window2->setObjectName(QString::fromUtf8("Window2"));
        Window2->resize(251, 161);
        pushButton = new QPushButton(Window2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 110, 93, 28));
        pushButton_2 = new QPushButton(Window2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 110, 93, 28));
        lineEdit = new QLineEdit(Window2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 80, 211, 21));
        lineEdit_2 = new QLineEdit(Window2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 30, 211, 21));
        label = new QLabel(Window2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 71, 16));
        label_2 = new QLabel(Window2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 55, 16));

        retranslateUi(Window2);

        QMetaObject::connectSlotsByName(Window2);
    } // setupUi

    void retranslateUi(QDialog *Window2)
    {
        Window2->setWindowTitle(QCoreApplication::translate("Window2", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Window2", "Aceptar", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Window2", "Cancelar", nullptr));
        label->setText(QCoreApplication::translate("Window2", "Contrase\303\261a", nullptr));
        label_2->setText(QCoreApplication::translate("Window2", "IP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window2: public Ui_Window2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW2_H
