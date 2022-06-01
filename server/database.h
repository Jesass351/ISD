#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class DataBase;

class DataBaseDestroyer
{
    private:
        DataBase * dataBasePointer;
    public:
        ~DataBaseDestroyer() {delete dataBasePointer;}
        void initialize(DataBase * p){dataBasePointer = p;}
};

class DataBase
{
    private:
        static DataBase * dataBasePointer;
        static DataBaseDestroyer destroyer;
        static QSqlDatabase db;
    protected:
        DataBase(){

            db = QSqlDatabase::addDatabase("QODBC");
            db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};FIL={MS Access};DSN='';DBQ=C:/Users/Artem/Desktop/PIS QT/server/dataBase/DataBase.accdb");

            if (!db.open())
                qDebug() << db.lastError().text();
        }
        DataBase(const DataBase&);
        DataBase& operator = (DataBase &);
        ~DataBase() {db.close();}
        friend class DataBaseDestroyer;
    public:
        static DataBase* getInstance(){
            if (!dataBasePointer)
            {
                dataBasePointer = new DataBase();
                destroyer.initialize(dataBasePointer);
            }
            return dataBasePointer;
        }







        static QString addEvent(QString id,QString date, QString weather, QString duration, QString conf, QString type, QString split, QString control, QString service){
                db.open();
                QSqlQuery query;
                query.prepare("INSERT INTO заезд VALUES (:id,:date, :weather, :duration,:conf,:type, :split, :control,:service)");
                query.bindValue(":id", id);
                query.bindValue(":date", date);
                query.bindValue(":weather", weather);
                query.bindValue(":duration", duration);
                query.bindValue(":conf", conf);
                query.bindValue(":type", type);
                query.bindValue(":split", split);
                query.bindValue(":control", control);
                query.bindValue(":service", service);


                if (query.exec()){
                    return "succes";
                }

                db.close();
                query.clear();
                return "not succes";

            }

        static QString auth(QString log, QString pass){
            db.open();
            qDebug() << log + " " + pass;
            QSqlQuery query;
            query.prepare("SELECT * FROM Users where login = :login and password = :password" );
            query.bindValue(":login", log);
            query.bindValue(":password", pass);
            query.exec();
            if (query.next()){
                return "True";
            }
            else return "False";
        }

        static QString reg(QString log, QString pass){
            db.open();
            qDebug() << log + " " + pass;
            QSqlQuery query;
            if (log == "" || pass == ""){
                return "EmptyField";
            }
            query.prepare("SELECT * FROM Users where login = :login" );
            query.bindValue(":login", log);

            query.exec();
            if (query.next()){
                return "AlreadyCreated";
            }
            else{
                query.prepare("INSERT INTO Users VALUES (:login, :password)" );
                query.bindValue(":login", log);
                query.bindValue(":password", pass);
                query.exec();
                return "True";
            }
            return "Smth went wrong...";
        }




        static QString getAll(){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.exec("SELECT * FROM заезд");
            while(query.next()){
                 result.append(query.value(0).toString());
                 result.append("|");
                 result.append(query.value(1).toString());
                 result.append("|");
                 result.append(query.value(2).toString());
                 result.append("|");
                 result.append(query.value(3).toString());
                 result.append("|");
                 result.append(query.value(4).toString());
                 result.append("|");
                 result.append(query.value(5).toString());
                 result.append("|");
                 result.append(query.value(6).toString());
                 result.append("|");
                 result.append(query.value(7).toString());
                 result.append("|");
                 result.append(query.value(8).toString());
                 result.append("}");
            }
            db.close();
            query.clear();
            return result;
        }

        static QString getControl(){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.exec("SELECT * FROM контролирующий_персонал");
            while(query.next()){
                 result.append(query.value(0).toString());
                 result.append("|");
                 result.append(query.value(1).toString());
                 result.append("|");
                 result.append(query.value(2).toString());
                 result.append("}");
            }
            db.close();
            query.clear();
            return result;
        }

        static QString getService(){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.exec("SELECT * FROM обслуживающий_персонал");
            while(query.next()){
                 result.append(query.value(2).toString());
                 result.append("|");
                 result.append(query.value(1).toString());
                 result.append("|");
                 result.append(query.value(0).toString());
                 result.append("}");
            }
            db.close();
            query.clear();
            return result;
        }
        static QByteArray getSplits(){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.exec("SELECT * FROM сплит");
            while(query.next()){
                 result.append(query.value(0).toString());
                 result.append("|");
                 result.append(query.value(1).toString());
                 result.append("|");
                 result.append(query.value(2).toString());
                 result.append("|");
                 result.append(query.value(3).toString());
                 result.append("}");
            }
            db.close();
            query.clear();
            return result;
        }
};



#endif // DATABASE_H
