/*!
 * \file
 */

#include "mytcpserver.h"

/*!
 * \brief Деструктор класса MyTcpServer.
*/
MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    //server_status=0;
}

/*!
 * \brief Конструктор класса MyTcpServer.
 * Конструктор класса в котором мы открываем сервер на прослушивание и подключаемся к базе данных.
*/
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    DataBase::getInstance();
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);
    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        //server_status=1;
        qDebug() << "server is started";
    }
}

/*!
 * \brief Метод класса MyTcpServer, который подключает пользователя к серверу и выводит ему приветствие.
*/
void MyTcpServer::slotNewConnection(){
 //   if(server_status==1){
        QTcpSocket *tempSocket;
        tempSocket = mTcpServer->nextPendingConnection();
        mTcpSocket.push_back(tempSocket);
        tempSocket->write("Hello, World!!! I am echo server!\r\n");
        connect(tempSocket, &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(tempSocket,&QTcpSocket::disconnected,this, &MyTcpServer::slotServerRead);
   // }
}


/*!
 * \brief Метод класса MyTcpServer, который считывает строку, которая вводится пользователем.
*/
void MyTcpServer::slotServerRead(){
    QTcpSocket *tempSock = (QTcpSocket*)sender();
    QString res="";
    while(tempSock->bytesAvailable()>0)
    {
        QByteArray array =tempSock->readAll();
        res.append(array);
        //mTcpSocket->write(array);
    }
    //qDebug()<<res+"pppp";
    QByteArray array = parsing(res);
    //qDebug()<<array+"pppp";
    qDebug()<<array;
    //qDebug()<<tempSock->socketDescriptor();
    tempSock->write(array);
}

/*!
 * \brief Метод класса MyTcpServer, который отключает пользователя от сервера.
*/
void MyTcpServer::slotClientDisconnected(){
        QTcpSocket *tempSock = (QTcpSocket*)sender();
        mTcpSocket.remove(tempSock);
        tempSock->close();
}
