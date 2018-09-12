#include "consumer.h"

#include <QDebug>
#include <QTime>
#include <QThread>
#include <QMutexLocker>

extern const int DataSize;
extern char buffer[];
extern const int BufferSize;
extern QMutex mutex;
extern qreal locx;
extern bool shutdownnow;
extern int shutdowncounter;
extern int shutdowncountmax;

void Consumer::run()
{
//    for (int i = 0; i < DataSize; ++i) {
//        QMutexLocker locker(&mutex);
//        //fprintf(stderr, "%c", buffer[i % BufferSize]);
//        qDebug() << buffer[i%BufferSize];
//    }
    //fprintf(stderr, "\n");

    while(shutdowncounter < shutdowncountmax)
    {
        //qDebug() <<"(consumer) set locx to " <<locx;
        QMutexLocker locker(&mutex);
        locx -= 0.0002;
//        msleep(1);
    }
    qDebug() <<"consumer set locx to " <<locx;

}
