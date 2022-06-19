#include "addclient.h"
#include "ui_addclient.h"

addClient::addClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addClient)
{
    ui->setupUi(this);
}

addClient::~addClient()
{
    delete ui;
}
