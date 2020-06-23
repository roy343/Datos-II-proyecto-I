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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *id;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *con;
    QLineEdit *puerto;
    QPushButton *b1;
    QPushButton *b2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Visualizer)
    {
        if (Visualizer->objectName().isEmpty())
            Visualizer->setObjectName(QString::fromUtf8("Visualizer"));
        Visualizer->resize(352, 199);
        centralwidget = new QWidget(Visualizer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(19, 19, 311, 91));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        id = new QLineEdit(formLayoutWidget);
        id->setObjectName(QString::fromUtf8("id"));

        formLayout->setWidget(0, QFormLayout::FieldRole, id);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        con = new QLineEdit(formLayoutWidget);
        con->setObjectName(QString::fromUtf8("con"));

        formLayout->setWidget(2, QFormLayout::FieldRole, con);

        puerto = new QLineEdit(formLayoutWidget);
        puerto->setObjectName(QString::fromUtf8("puerto"));

        formLayout->setWidget(1, QFormLayout::FieldRole, puerto);

        b1 = new QPushButton(centralwidget);
        b1->setObjectName(QString::fromUtf8("b1"));
        b1->setGeometry(QRect(40, 120, 93, 28));
        b2 = new QPushButton(centralwidget);
        b2->setObjectName(QString::fromUtf8("b2"));
        b2->setGeometry(QRect(220, 120, 93, 28));
        Visualizer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Visualizer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 352, 26));
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
        label->setText(QCoreApplication::translate("Visualizer", "Servidor", nullptr));
        label_2->setText(QCoreApplication::translate("Visualizer", "Puerto", nullptr));
        label_3->setText(QCoreApplication::translate("Visualizer", "Constrase\303\261a", nullptr));
        b1->setText(QCoreApplication::translate("Visualizer", "Aceptar", nullptr));
        b2->setText(QCoreApplication::translate("Visualizer", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Visualizer: public Ui_Visualizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZER_H
