#ifndef FUNCTIONS_FOR_CLIENT_H
#define FUNCTIONS_FOR_CLIENT_H
#include <QString>
#include <QDebug>
#include "client.h"

QString auth(QString log, QString pass);
QString reg(QString log, QString pass);

QString getAll();
QString addEvent(QString id,QString time, QString weather, QString duration, QString  conf , QString type, QString  split , QString control, QString service);
QString getService();
QString getControl();
QString getSplits();
QString getSplitInfo(QString num);
QString getClientCount(QString num);
QString addClient(QString a,QString b, QString c, QString rent, QString license, QString split);
QString addSplitS(QString name);
#endif // FUNCTIONS_FOR_CLIENT_H
