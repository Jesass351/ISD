#include "servicetable.h"
#include "ui_servicetable.h"
#include <qdebug.h>
#include "functions_for_client.h"
#include "posts.h"
serviceTable::serviceTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::serviceTable)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    addtoTable(getService());
}

serviceTable::~serviceTable()
{
    delete ui;
}

void serviceTable::on_pushButton_clicked()
{
    close();
}
void serviceTable::addtoTable(QString data){

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

void serviceTable::on_pushButton_2_clicked()
{
     Client::send_request_to_server("addService&"+ui->fam->text() +"&"+ui->name->text() +"&"+ui->otch->text() +"&"+ui->post->text() +"&" + ui->place->text()+"&");
     addtoTable(getService());
}


void serviceTable::on_pushButton_3_clicked()
{
    dataP = Client::send_request_to_server("getPostsSer&1&");
    posts table;
    table.setModal(true);
    table.exec();
}

