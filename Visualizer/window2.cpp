#include "window2.h"
#include "ui_window2.h"
#include "visualizer.h"
#include <QFileDialog>
#include <QTextStream>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMessageBox>
#include <QTcpSocket>


Window2::Window2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window2)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    /*! Establece el socket para ser ejecutado en la segunda ventana */
    connect(mSocket,&QTcpSocket::readyRead, [&](){
        QTextStream T(mSocket);
        ui ->lista->addItem(T.readAll());
    });
}

Window2::~Window2()
{
    delete ui;
}

/*! Funcion que lee un archivo .json y muestra su contenido cuando se llama el boton  */
void Window2::on_b1_clicked()
{
    //mSocket->connectToHost(ui->id->text(),ui->puerto->value());
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
}
