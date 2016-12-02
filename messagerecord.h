#ifndef MESSAGERECORD_H
#define MESSAGERECORD_H


#include<QVector>
#include<QString>
#include"message.h"

class MessageRecord
{
public:
    MessageRecord();
    void addMessage(const Message & msg){MessageList.push_back(msg);}
    QVector<Message>& selectAllMessage();
private:
    //记得上锁
    QVector<Message> MessageList;
};

#endif // MESSAGERECORD_H
