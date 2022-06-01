#include "eventadd.h"
#include "ui_eventadd.h"
#include <QMessageBox>
#include <QTableWidget>
#include "servicetable.h"
#include "controltable.h"

eventAdd::eventAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eventAdd)
{
    ui->setupUi(this);

}

eventAdd::~eventAdd()
{
    delete ui;
}

void eventAdd::on_pushButton_clicked()
{


    QString resultFromServer = addEvent(ui->id->text(), ui->time->text() , ui->weather->text(),ui->duration->text(), ui->conf->text(),ui->type->text(), ui->split->text(), ui->split->text(), ui->split->text());
    if (resultFromServer == "succes"){
    close();
    } else {
        QMessageBox notcorrect;
        notcorrect.setText("Проверьте правильность введённых данных");
        notcorrect.exec();
    }

}





void eventAdd::on_pushButton_3_clicked()
{

    serviceTable table;
    table.setModal(true);
    table.exec();


}


void eventAdd::on_pushButton_4_clicked()
{
    controltable table;
    table.setModal(true);
    table.exec();
}

