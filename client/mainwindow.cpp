#include "mainwindow.h"


Client * client;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Client::getInstance();
    ui_auth = new AuthWindow;
    ui_auth->show();
    connect(ui_auth, &AuthWindow::send_data, this, &MainWindow::slot_show);
    ui->MainTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->MainTable->setColumnCount(9);
    ui->MainTable->setRowCount(0);
    ui->MainTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Номер заезда"));
    ui->MainTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Время заезда"));
    ui->MainTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Погодные условия"));
    ui->MainTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Продолжительность"));
    ui->MainTable->setHorizontalHeaderItem(4, new QTableWidgetItem("Конфигурация"));
    ui->MainTable->setHorizontalHeaderItem(5, new QTableWidgetItem("Тип заезда"));
    ui->MainTable->setHorizontalHeaderItem(6, new QTableWidgetItem("Сплит"));
    ui->MainTable->setHorizontalHeaderItem(7, new QTableWidgetItem("controlId"));
    ui->MainTable->setHorizontalHeaderItem(8, new QTableWidgetItem("serviceId"));
}

MainWindow::~MainWindow()
{
    delete ui_auth;
    delete ui;

}

void MainWindow::slot_show(QString log)
{
    QString user_login = log;
    QPixmap LogoPic(":/resources/img/logo.png"); //лого слева сверху
    ui->logo->setPixmap(LogoPic);
    ui->logo->hide();
    ui->NameOfUser->setText(log);
    show();
}

//EXIT

void MainWindow::on_actionExit_triggered(bool checked)
{
    close();
}




void MainWindow::on_pushButton_2_clicked()
{

//    setserviceInfo(getService());
    eventAdd event;
    event.setModal(true);
    event.exec();

}


void MainWindow::on_pushButton_clicked()
{
     addToMainTable(getAll());
}


void MainWindow::on_splits_clicked()
{
    split window;
    window.setModal(true);
    window.exec();
}

