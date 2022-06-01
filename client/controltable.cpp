#include "controltable.h"
#include "ui_controltable.h"
#include "functions_for_client.h"

controltable::controltable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::controltable)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QString dataFromServer = getControl();
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

controltable::~controltable()
{
    delete ui;
}

void controltable::on_pushButton_clicked()
{
    close();
}

