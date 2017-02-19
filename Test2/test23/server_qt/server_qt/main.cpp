#include <iostream>
#include "server.h"
#include <QCoreApplication>
#include <QThread>

using namespace std;

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    ~Server();

signals:
    void runWorker( QTcpSocket *socket );
    void dataRead(int);

public slots:
    void start();
    void onNewConnection();
    void onBytesWritten(qint64 bytes);
    void onReadyRead();

private:
    QTcpServer* m_server;
};
Server::Server(QObject *parent)
    : QObject(parent)
    , m_server(new QTcpServer(this))
{
}
class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);

signals:

public slots:
    void doWork();
};

Server::~Server()
{
    delete m_server;
}

void Server::start()
{
    connect(m_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));

    if(!m_server->listen(QHostAddress::Any, 9999))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

void Server::onNewConnection()
{
    qDebug() << "Connected (server)!";

    QTcpSocket *socket = m_server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void Server::onBytesWritten(qint64 bytes)
{
    qDebug() << "We wrote: " << bytes << " bytes";

    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());
    socket->close();
}


void Server::onReadyRead()
{
    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());

    QByteArray data = socket->readAll();
    QString s_data = QString::fromUtf8(data.data());

    qDebug() << "Read: " << s_data << endl;
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(onBytesWritten(qint64)));

    socket->write("Response from server!");

    emit dataRead(data.size());
}
Worker::Worker(QObject *parent) : QObject(parent)
{

}

void Worker::doWork(QTcpSocket *socket)
{

}


int main(//int argc, char *argv[]
         )
{
    cout << "Enter!" << endl;

    QCoreApplication app(argc, argv);

    Server s;

    QThread th1;
    s.moveToThread(&th1);
    s.connect(&th1, SIGNAL(started()), &s, SLOT(start()));
    th1.start();

    s.connect(&s, &Server::dataRead, [](int size)
                                    {

                                        qDebug() << "Data read: " << size;
                                    });

    return 0;
            //app.exec();
}
