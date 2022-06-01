#ifndef FUNCTIONS_FOR_CLIENT_H
#define FUNCTIONS_FOR_CLIENT_H
#include <QString>
#include <QDebug>
#include "client.h"

QString auth(QString log, QString pass);
QString reg(QString log, QString pass);

QString getAll();
QString addEvent(QString id, QString time, QString weather, QString duration, QString  conf , QString type, QString  split , QString control, QString service);
QString getService();
QString getControl();
QString getSplits();

#endif // FUNCTIONS_FOR_CLIENT_H
