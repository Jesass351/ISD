#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include "functionsforserver.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <list>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

//#include <iostream>

/*!
* \brief MyTcpServer - главный класс сервера.
*
* Класс MyTcpServer на основе QTcpServer, который реализует всю основную логику работы сервера.
*/

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
private:
    QTcpServer * mTcpServer;
    std::list<QTcpSocket*> mTcpSocket;
    //int server_status;
};

#endif // MYTCPSERVER_H







