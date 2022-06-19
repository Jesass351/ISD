#include "addsplit.h"
#include "ui_addsplit.h"
#include "functions_for_client.h"
#include <QMessageBox>
addSplit::addSplit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addSplit)
{
    ui->setupUi(this);
}

addSplit::~addSplit()
{
    delete ui;
}

void addSplit::on_pushButton_clicked()
{
        QMessageBox box;
    if(addSplitS(ui->nameOfSplit->text()) == "succes"){

        box.setText("Успешно");
        box.exec();
    }
        else{
            box.setText("Что-то не так");
            box.exec();
        }

    }


