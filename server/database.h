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
            db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};FIL={MS Access};DSN='';DBQ=C:/Users/Artem/Desktop/PIS QT/server/dataBase/DataBase3.accdb");
//            db = QSqlDatabase::addDatabase("QMYSQL");
//            QString path = "..//server/dataBase/";
//             db.setDatabaseName(path + "track.mwb");


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
                query.prepare("INSERT INTO заезд VALUES (:id, :date, :weather, :duration,:conf,:type, :split, :control,:service)");
                query.bindValue(":date", date);
                query.bindValue(":weather", weather);
                query.bindValue(":duration", duration);
                query.bindValue(":conf", conf);
                query.bindValue(":type", type);
                query.bindValue(":split", split);
                query.bindValue(":control", control);
                query.bindValue(":service", service);

                QSqlQuery queryID;
                QString ID;
                queryID.exec("SELECT COUNT(Время) FROM заезд");
                while(queryID.next()){

                    ID.append(queryID.value(0).toString());
                }
                query.bindValue(":id", (ID.toInt()+1));


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
            query.clear();
            db.close();
            //return "True";
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
            query.clear();
            return "Smth went wrong...";
            db.close();
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
            db.close();
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
                result.append("|");
                result.append(query.value(3).toString());
                result.append("|");
                result.append(query.value(4).toString());
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
                 result.append("}");
            }
            db.close();
            query.clear();
            return result;
        }
        static QByteArray addControl(QString a, QString b, QString c, QString post){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.prepare("INSERT INTO контролирующий_персонал values (:id, :a,:b,:c, :post)");
            query.bindValue(":a", a);
            query.bindValue(":b", b);
            query.bindValue(":c", c);
            query.bindValue(":post", post.toInt());
            QSqlQuery queryID;
            QString ID;
            queryID.exec("SELECT COUNT(Фамилия) FROM контролирующий_персонал");
            while(queryID.next()){

                ID.append(queryID.value(0).toString());
            }

            query.bindValue(":id", (ID.toInt()+1));
            query.exec();
            query.clear();
            return result;
        }
        static QByteArray addService(QString a, QString b, QString c, QString post,QString place){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.prepare("INSERT INTO обслуживающий_персонал values (:id, :a,:b,:c, :post, :place)");
            query.bindValue(":a", a);
            query.bindValue(":b", b);
            query.bindValue(":c", c);
            query.bindValue(":post", post.toInt());
            query.bindValue(":place", place);
            QSqlQuery queryID;
            QString ID;
            queryID.exec("SELECT COUNT(Фамилия) FROM обслуживающий_персонал");
            while(queryID.next()){

                ID.append(queryID.value(0).toString());
            }

            query.bindValue(":id", (ID.toInt()+1));
            query.exec();
            query.clear();
            db.close();
            return result;
        }
        static QByteArray getSplitInfo(QString num){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.prepare("SELECT * FROM клиент WHERE Сплит=:id");
            query.bindValue(":id", num);
            query.exec();
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
                 result.append("}");
            }
            query.clear();
            return result;
            db.close();
        }
        static QByteArray getCountClient(QString num){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.prepare("SELECT COUNT(*) as count FROM клиент WHERE СплитID=:id");
            query.bindValue(":id", num);
            query.exec();
            while(query.next()){
                 result.append(query.value(0).toString());
            }
            query.clear();
            return result;
            db.close();
        }

        static QByteArray addClient(QString a, QString b, QString c, QString idrent, QString license, QString split){
            QByteArray result;
            db.open();
            QSqlQuery query;

            query.prepare("INSERT INTO клиент VALUES (:id, :a, :b, :c, :idrent, :license, :split)");

            query.bindValue(":a", a);
            query.bindValue(":b", b);
            query.bindValue(":c", c);
            query.bindValue(":idrent", idrent.toInt());
            query.bindValue(":license", license.toInt());
            query.bindValue(":split", split.toInt());
            QSqlQuery queryID;
            QString ID;
            queryID.exec("SELECT COUNT(Имя) FROM клиент");
            while(queryID.next()){

                ID.append(queryID.value(0).toString());
            }

            query.bindValue(":id", (ID.toInt()+1));
            if(query.exec()){
             result.append("true");
            }
            else result.append("false");
            query.clear();
            queryID.clear();
            return result;
            db.close();
        }
        static QByteArray addSplit(QString name){
            QByteArray result;
            db.open();
            QSqlQuery query;

            query.prepare("INSERT INTO сплит VALUES (:id, :name)");

            query.bindValue(":name", name);

            QSqlQuery queryID;
            QString ID;
            queryID.exec("SELECT COUNT(idСплит) FROM сплит");
            while(queryID.next()){

                ID.append(queryID.value(0).toString());
            }

            query.bindValue(":id", (ID.toInt()+1));
            if(query.exec()){
             result.append("succes");
            }
            else result.append("false");
            query.clear();
            queryID.clear();
            return result;
            db.close();
        }
        static QByteArray addRent(QString name){
            QByteArray result;
            db.open();
            QSqlQuery query;

            query.prepare("INSERT INTO аренда VALUES (:id, :name)");

            query.bindValue(":name", name);


            QSqlQuery queryID;
            QString ID;
            queryID.exec("SELECT COUNT(idАренда) FROM аренда");
            while(queryID.next()){

                ID.append(queryID.value(0).toString());
            }

            query.bindValue(":id", (ID.toInt()+1));
            if(query.exec()){
             result.append(ID+1);
            }
            else result.append("false");
            query.clear();
            queryID.clear();
            return result;
            db.close();
        }
        static QByteArray getPostsSer(QString num){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.exec("SELECT * FROM обс_должности");
                while(query.next()){
                     result.append(query.value(0).toString());
                    result.append("|");
                    result.append(query.value(1).toString());
                    result.append("}");
                }

            query.clear();
            return result;
            db.close();
        }
        static QByteArray getPostsCont(QString num){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.exec("SELECT * FROM контр_должности");
                while(query.next()){
                     result.append(query.value(0).toString());
                    result.append("|");
                    result.append(query.value(1).toString());
                    result.append("}");
                }

            query.clear();
            return result;
            db.close();
        }
        static QByteArray getLicense(){
            QByteArray result;
            db.open();
            QSqlQuery query;
            query.exec("SELECT * FROM лиц_список");
                while(query.next()){
                     result.append(query.value(0).toString());
                    result.append("|");
                    result.append(query.value(1).toString());
                    result.append("}");
                }

            query.clear();
            return result;
            db.close();
        }
};



#endif // DATABASE_H
