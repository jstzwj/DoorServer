#include "netconnection.h"
#include<iostream>
NetConnection::NetConnection(QObject *parent)
    : QObject(parent)
{

}

NetConnection::~NetConnection()
{

}

void NetConnection::searchController()
{
    PacketShort msg;
    msg.type=0x17;
    msg.functionID=0x94;
    memset(&msg,0,sizeof(msg));
    this->sendData(msg,QHostAddress("255.255.255.255"),61003);
}

void NetConnection::initSocket()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::LocalHost, 60000);
    //用于读写数据
    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(readPendingDatagrams()));

}
void NetConnection::stopSocket()
{
    udpSocket->disconnectFromHost();
}

void NetConnection::sendData(const QString &data, QHostAddress ip, quint16 port)//61003
{
    udpSocket->writeDatagram(data.toUtf8(),ip,port);
}
void NetConnection::sendData(PacketShort data, QHostAddress ip, quint16 port)//61003
{
    udpSocket->writeDatagram((char *)(&data),ip,port);
}
void NetConnection::readPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams())
    {
        //QByteArray datagram;
        PacketShort datagram;
        //datagram.resize(udpSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        udpSocket->readDatagram((char *)(&datagram), 1024,
                                &sender, &senderPort);
        Message msg;
        msg.type=datagram.type;
        msg.time=QDateTime::currentDateTime();
        msg.functionId=datagram.functionID;
        msg.devSn=datagram.iDevSn;
        msg.sequenceId=datagram.sequenceId;
        msg.data=QString((char *)datagram.data);
        msg.type=datagram.type;
        record.addMessage(msg);
        /*
        sqlite3 *db=NULL;
        int rc = sqlite3_open("data.db", &db);
        if(rc)
        {
            qDebug()<<"Open database failed!\n";
        }
        else
        {
            qDebug()<<"open the database successful!\n";
        }
        sqlite3_exec(db,
                     ("insert into raw_message (msg,time)values(\'"+QString(datagram)+"\'',\'"+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")+"\'');").toStdString().c_str(),
                     0, 0, NULL);
        sqlite3_close(db);
        */
        //processTheDatagram(datagram);
    }
}
