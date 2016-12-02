#ifndef NETCONNECTION_H
#define NETCONNECTION_H
#include<QObject>
#include<QtNetwork/QUdpSocket>
#include<QtNetwork/QHostAddress>
#include<QDateTime>
#include<QString>

#include"database/sqlite3.h"
#include"messagerecord.h"
#include"message.h"

typedef struct struPacketShort
{
    unsigned char	 type;				  //类型
    unsigned char	 functionID;		      //功能号
    unsigned short	 reserved;              //保留
    unsigned int	 iDevSn;               //设备序列号 4字节
    unsigned char  data[32];              //32字节的数据
    unsigned int   sequenceId;            //数据包流水号
    unsigned char  extern_data[20];        //第二版本 扩展20字节
}*pPacketShort, PacketShort;    //报文


class NetConnection:public QObject
{
    Q_OBJECT
public:
    NetConnection(QObject *parent = 0);
    ~NetConnection();
public:
    void searchController();
public slots:
    void initSocket();
    void stopSocket();
    void sendData(const QString &data, QHostAddress ip, quint16 port);
    void sendData(PacketShort data, QHostAddress ip, quint16 port);
    void readPendingDatagrams();
signals:
    void refreshMessageList(const QVector<Message>& list);
private:
    QUdpSocket * udpSocket;
    MessageRecord record;
};
#endif // NETCONNECTION_H
