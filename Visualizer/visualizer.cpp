#include "visualizer.h"
#include "ui_visualizer.h"
#include "window2.h"
#include <QFileDialog>
#include <QTextStream>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMessageBox>
#include "window2.cpp"

Visualizer::Visualizer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Visualizer)
{
    ui->setupUi(this);

}

Visualizer::~Visualizer()
{
    delete ui;
}


void Visualizer::on_b1_clicked()
{
    QString id = ui->id->text();
    QString puerto = ui->puerto->text();
    QString con = ui->con->text();

    if(id == "1234" && con == "1234"){
        Window2 win2;
        win2.setModal(true);
        win2.exec();
    };






//    Window2 win2;
//    win2.setModal(true);
//    win2.exec();
}





void Visualizer::on_probar_clicked()
{

}
