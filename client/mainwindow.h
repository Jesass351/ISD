#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QString>
#include <QInputDialog>





#include "QMessageBox"
#include <QPixmap>


#include "client.h"
#include "authwindow.h"
#include "eventadd.h"
#include "servicetable.h"
#include "split.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//    inline static QString serviceInfo;
//    static void setserviceInfo(QString newInfo){
//        serviceInfo = newInfo;
//    }
//    static QString getserviceInfo(){
//        return serviceInfo;
//    }


//    inline static QString controlInfo;
//    static void setcontrolInfo(QString newInfo){
//        serviceInfo = newInfo;
//    }
//    static QString getcontrolInfo(){
//        return controlInfo;
//    }



    void addToMainTable(QString dataFromServer){

        ui->MainTable->clearContents();

        if (dataFromServer == " "){
            QMessageBox nullBox;
            nullBox.setText("Увы, такого тут нет((");
            nullBox.exec();
        }
        else {

            for ( int i = 0; i < ui->MainTable->rowCount(); ++i )
            {
                ui->MainTable->removeRow(i);
            }
            QStringList bigRecord = dataFromServer.split(QLatin1Char('}'));
            for (int i = 0; i<bigRecord.length(); i++){
                ui->MainTable->setRowCount(ui->MainTable->rowCount()+1);
                QStringList oneRecord = bigRecord[i].split("|");
                for (int j = 0; j<oneRecord.length(); j++){

                        QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(oneRecord[j]));
                        qDebug() << item->text();
                        ui->MainTable->setItem(i,j, item);
                    }

                }
            }
        }



private:
    Ui::MainWindow *ui;
    AuthWindow *ui_auth;



private slots:
    void slot_show(QString log);

    void on_actionExit_triggered(bool checked);

    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_splits_clicked();
};
#endif // MAINWINDOW_H
