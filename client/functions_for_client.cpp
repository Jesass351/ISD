#include "functions_for_client.h"

QString auth(QString log, QString pass){
    QString res = "auth&" + log + "&" + pass + "&";
    return Client::send_request_to_server(res);
}

QString reg(QString log, QString pass){
    QString res = "reg&" + log + "&" + pass + "&";
    return Client::send_request_to_server(res);
}

QString check_statistic(){
    QString res = "checkstat&";
    return Client::send_request_to_server(res);
}


void update_statistic(){
    QString res = "updatestat&";
    qDebug() << res;
    Client::send_request_to_server(res);

}




QString searchSetByCar(QString car){
    QString res = "searchByCar&" + car + "&";
    qDebug() << res;
    return Client::send_request_to_server(res);
}

QString searchSetByTrack(QString track){
    QString res = "searchByTrack&" + track + "&";
    qDebug() << res;
    return Client::send_request_to_server(res);
}

QString getAll(){
    QString res = "getAll&";
    qDebug() << res;
    return Client::send_request_to_server(res);
}


QString addEvent(QString id, QString time, QString weather, QString duration, QString  conf , QString type, QString  split , QString control, QString service){
    QString res = "addEvent&" + id +"&"+time  + "&" + weather + "&" + duration + "&" + conf + "&" + type + "&" + split + "&" + control + "&" + service + "&";
    return Client::send_request_to_server(res);
}

QString getService(){
    QString res = "getService&";
    return Client::send_request_to_server(res);
}
QString getControl(){
    QString res = "getControl&";
    return Client::send_request_to_server(res);
}

QString getSplits()
{
    QString res = "getSplits&";
    return Client::send_request_to_server(res);
}

QString getSplitInfo(QString num){
    QString res = "getSplitInfo&" + num + "&";
    return Client::send_request_to_server(res);
}

QString getClientCount(QString num){
    QString res = "getCountClient&" + num + "&";
    return Client::send_request_to_server(res);
}

QString addClient(QString a, QString b, QString c, QString rent, QString license, QString split){
    QString res = "addClient&" + a+ "&" + b +"&"+"&" + c +"&" + rent + "&" + license + "&" + split + "&";
    return Client::send_request_to_server(res);
}

QString addSplitS(QString name){
    QString res = "addSplit&" + name+ "&";
    return Client::send_request_to_server(res);
}
