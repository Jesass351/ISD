#include "servicetable.h"
#include "ui_servicetable.h"
#include <qdebug.h>
#include "functions_for_client.h"

serviceTable::serviceTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::serviceTable)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QString dataFromServer = getService();
    ui->tableWidget->clearContents();
    for ( int i = 0; i < ui->tableWidget->rowCount(); ++i )
    {
        ui->tableWidget->removeRow(i);
    }
    QStringList bigRecord = dataFromServer.split(QLatin1Char('}'));
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

serviceTable::~serviceTable()
{
    delete ui;
}

void serviceTable::on_pushButton_clicked()
{
    close();
}

