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
#include <QTcpSocket>
#include "window2.cpp"
#include <QTextStream>
#include "window2.h"
#include "md5.h"
#include <string>
#include <chrono>

Visualizer::Visualizer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Visualizer)
{
    ui->setupUi(this);
    /*! Se estabalce el socket */
    mSocket = new QTcpSocket(this);

    connect(mSocket,&QTcpSocket::readyRead, [&](){
        QTextStream T(mSocket);
    });

}

Visualizer::~Visualizer()
{
    delete ui;
}

/*! Metodo que se ejecuta cuando se llama al boton */
void Visualizer::on_b1_clicked()
{
    /*! Se establecen las entradas de la interfaz en cada variable */
    QString id = ui->id->text();
    QString con = ui->con->text();

    /*! Se pasa la entrada a un StdString y  se ejecuta el md5 */
    std::string str = con.toStdString();
    str.c_str();
    std::string x = md5(str);
    qInfo()<<QString::fromStdString(x);

    /*! Cuando el id y la contrasena son las correctas entonces se ejecuta
        la segunda ventana donde esta el visualizer*/
    if(id == "1234" && con == "1234"){
        mSocket->connectToHost(ui->id->text(),ui->puerto->value());


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
