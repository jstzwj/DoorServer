#ifndef MESSAGE_H
#define MESSAGE_H
#include<QString>
#include<QDateTime>

class Message
{
public:
    Message();
    QString type;
    QString functionId;
    QString devSn;
    QString data;
    QString sequenceId;
    QString ip;
    QDateTime time;
};

#endif // MESSAGE_H
