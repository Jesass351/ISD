#include "posts.h"
#include "ui_posts.h"
#include "servicetable.h"
#include "controltable.h"
#include <QDebug>
posts::posts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::posts)
{
    ui->setupUi(this);
    QString data = serviceTable::getData();
    qDebug() << data;
     addtoTable(data);
}

posts::~posts()
{
    delete ui;
}

void posts::on_pushButton_clicked()
{
    close();
}

void posts::addtoTable(QString data){

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
                ui->tableWidget->setItem(i,j, item);
            }

        }
}
