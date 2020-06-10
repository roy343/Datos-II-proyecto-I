#include "visualizer.h"
#include "ui_visualizer.h"

Visualizer::Visualizer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Visualizer)
{
    ui->setupUi(this);
    ui->lista->addItem("tipo, valor, ubicacion, referencias");
}

Visualizer::~Visualizer()
{
    delete ui;
}

