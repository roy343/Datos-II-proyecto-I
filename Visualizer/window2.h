#ifndef WINDOW2_H
#define WINDOW2_H

#include <QDialog>
#include <QTcpSocket>

namespace Ui {
class Window2;
}

class QTcpSocket;



class Window2 : public QDialog
{
    Q_OBJECT

public:
    explicit Window2(QWidget *parent = nullptr);
    ~Window2();

private slots:
    void on_b21_clicked();

    void on_pushButton_clicked();

    void on_b1_clicked();

private:
    Ui::Window2 *ui;
    QTcpSocket *mSocket;
};

#endif // WINDOW2_H
