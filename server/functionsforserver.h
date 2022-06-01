#ifndef FUNCTIONSFORSERVER_H
#define FUNCTIONSFORSERVER_H
#include "database.h"
#include <QString>
#include <QStringList>


QByteArray parsing(QString data_from_client);
QByteArray auth(QString login, QString pass);
QByteArray reg(QString login, QString pass);
QByteArray all();
QByteArray addEvent(QString id, QString date, QString weather, QString duration, QString conf, QString type, QString split, QString control, QString service);
QByteArray getService();
QByteArray getControl();
#endif // FUNCTIONSFORSERVER_H
