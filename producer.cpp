#include "producer.h"

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


void Producer::run()
{
//    qsrand(static_cast<uint>(QTime(0,0,0).secsTo(QTime::currentTime())));
//    for (int i = 0; i < DataSize; ++i) {
//        QMutexLocker locker(&mutex);
//        buffer[i % BufferSize] = "ACGT"[static_cast<int>(qrand()) % 4];
//    }

    while(shutdowncounter < shutdowncountmax)
    {
        //qDebug() << "(producer)  shutdowncounter: " << shutdowncounter << "   shutdowncountmax:" << shutdowncountmax;
        //qDebug() <<"(producer) set locx to " <<locx;
        QMutexLocker locker(&mutex);
        locx += 0.0001;
//        msleep(1);
    }
}
