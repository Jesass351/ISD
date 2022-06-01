#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QString>

class Client;

class ClientDestroyer
{
    private:
        Client * p_instance;
    public:
        ~ClientDestroyer() {delete p_instance;};
        void initialize(Client * p){p_instance = p;}
};

class Client : public QObject
{
    Q_OBJECT
    private:
        static Client * p_instance;
        static ClientDestroyer destroyer;
        static QTcpSocket mysocket;
        inline static QString ResulForClient;
    protected:
        Client(QObject *parent = nullptr) : QObject(parent){
            mysocket.connectToHost("127.0.0.1",33333);

            connect(&mysocket, &QTcpSocket::readyRead,this,&Client::slotClientRead);
            connect(&mysocket,&QTcpSocket::disconnected,this,&Client::slotDisconnected);
        }

        Client(const Client& )= delete;
        Client& operator = (Client &) = delete;
        ~Client() {
            //AuthWindow::clearNameOfUser();

            mysocket.close();
        }
        friend class ClientDestroyer;

    public:
        static Client* getInstance(){
            if (!p_instance)
            {
                p_instance = new Client();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
//        static void send_request_to_server(QString res){
//            mysocket.write(res.toLocal8Bit());

//        }


         static QString send_request_to_server(QString res){
            ResulForClient = "ErrorRead";
            QByteArray ResultForServer;
            ResultForServer += res.toUtf8();
            mysocket.write(ResultForServer);
            mysocket.waitForReadyRead(100);
            return ResulForClient;
        }


    public slots:

    void slotDisconnected()
    {

        mysocket.close();
    }
    static void slotClientRead(){
        QByteArray FromServer = mysocket.readAll();
        ResulForClient = QString(FromServer);
    }

};
#endif // CLIENT_H
