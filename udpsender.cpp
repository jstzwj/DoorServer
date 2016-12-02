#include "udpsender.h"

UdpSender::UdpSender()
{
    socket=new QUdpSocket;

}

UdpSender::~UdpSender()
{
    delete socket;
}
