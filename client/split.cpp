#include "split.h"
#include "ui_split.h"
#include "functions_for_client.h"
#include "aboutsplit.h"
#include "addsplit.h"
split::split(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::split)
{
    ui->setupUi(this);
}

split::~split()
{
    delete ui;
}

void split::on_refresh_clicked()
{
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QString dataFromServer = getSplits();
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


void split::on_detailed_clicked()
{
    splitNum = ui->splitNum->text();
    AboutSplit about;
    about.setModal(true);
    about.exec();
}




void split::on_addPilot_clicked()
{

}


void split::on_addSplit_clicked()
{
    addSplit split;
    split.setModal(true);
    split.exec();
}

