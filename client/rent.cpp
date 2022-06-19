#include "rent.h"
#include "ui_rent.h"
#include "client.h"
#include <QMessageBox>
rent::rent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rent)
{
    ui->setupUi(this);
}

rent::~rent()
{
    delete ui;
}

void rent::on_pushButton_clicked()
{
    QString res = Client::send_request_to_server("addRent&" + ui->name->text() + "&");
    QMessageBox box;
    box.setText(res);
    box.exec();

}

