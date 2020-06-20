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
    ui->lista->addItem("hello");
    QString archivo = "C:/Users/Dell/Desktop/prueba.json";
        //Variables necesarias
        QJsonArray arr;
        QJsonDocument doc;
        QJsonObject obj;
        QByteArray data_json;

        //Abre el docuemento y guarda los datos en las variables
        QFile input(archivo);
        input.open(QIODevice::ReadOnly | QIODevice::Text);
        data_json = input.readAll();
        doc = doc.fromJson(data_json);
        obj =doc.object();

        //Muestra los datos del documento
        QString valor = obj["datos"].toString();
        QString valor1 = obj["datos1"].toString();
        ui->lista->addItem(valor);
        ui->lista->addItem(valor1);





    //Window2 win2;
    //win2.setModal(true);
    //win2.exec();
}
