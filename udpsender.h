#ifndef UDPSENDER_H
#define UDPSENDER_H

#include<QtNetwork/QUdpSocket>

class UdpSender
{
private:
    QUdpSocket *socket;
public:
    UdpSender();
    ~UdpSender();
    QString send();
};

#endif // UDPSENDER_H
