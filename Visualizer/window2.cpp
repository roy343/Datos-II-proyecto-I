#include "window2.h"
#include "ui_window2.h"
#include "visualizer.h"

Window2::Window2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window2)
{
    ui->setupUi(this);
}

Window2::~Window2()
{
    delete ui;
}
void Window2::on_b21_clicked(){

}
