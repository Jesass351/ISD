#include "controltable.h"
#include "ui_controltable.h"
#include "functions_for_client.h"
#include "posts.h"
#include "servicetable.h"
controltable::controltable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::controltable)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    addtoTable(getControl());
}



controltable::~controltable()
{
    delete ui;
}

void controltable::on_pushButton_clicked()
{
    close();
}


void controltable::addtoTable(QString data){

    ui->tableWidget->clearContents();
    for ( int i = 0; i < ui->tableWidget->rowCount(); ++i )
    {
        ui->tableWidget->removeRow(i);
    }
    QStringList bigRecord = data.split(QLatin1Char('}'));
    for (int i = 0; i<bigRecord.length(); i++){
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        QStringList oneRecord = bigRecord[i].split("|");
        for (int j = 0; j<oneRecord.length(); j++){

                QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(oneRecord[j]));
                qDebug() << item->text();
                ui->tableWidget->setItem(i,j, item);
            }

        }
}

void controltable::on_add_clicked()
{
    Client::send_request_to_server("addControl&"+ui->fam->text() +"&"+ui->name->text() +"&"+ui->otch->text() +"&"+ui->post->text() +"&");
    addtoTable(getControl());
}


void controltable::on_pushButton_2_clicked()
{
    serviceTable::setData(Client::send_request_to_server("getPostsContr&1&"));
    posts table;
    table.setModal(true);
    table.exec();
}

