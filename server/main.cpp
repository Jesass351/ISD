
#include "database.h"
#include "mytcpserver.h"
#include <QCoreApplication>


DataBase * DataBase::dataBasePointer;
DataBaseDestroyer DataBase::destroyer;
QSqlDatabase DataBase::db;

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    MyTcpServer myserv;
    return a.exec();
}
