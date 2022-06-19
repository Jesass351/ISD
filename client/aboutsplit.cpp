#include "aboutsplit.h"
#include "ui_aboutsplit.h"
#include "split.h"
#include "functions_for_client.h"
#include "rent.h"
#include "servicetable.h"
#include "posts.h"
AboutSplit::AboutSplit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutSplit)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

AboutSplit::~AboutSplit()
{
    delete ui;
}

void AboutSplit::on_pushButton_2_clicked()
{
    close();
}


void AboutSplit::on_pushButton_3_clicked()
{
    QString dataFromServer = getSplitInfo(split::getSplitNum());
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
                    //qDebug() << item->text();
                    ui->tableWidget->setItem(i,j, item);
                }
            }

        }



void AboutSplit::on_addClient_clicked()
{
    addClient(ui->fam->text() ,ui->name->text(), ui->otch->text(),ui->idRent->text(), ui->license->text(), split::getSplitNum());
}


void AboutSplit::on_pushButton_clicked()
{
    rent page;
    page.setModal(true);
    page.exec();
}


void AboutSplit::on_pushButton_4_clicked()
{
    serviceTable::setData(Client::send_request_to_server("getLicense&"));
    posts page;
    page.setModal(true);
    page.exec();
}

