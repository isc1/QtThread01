#include "producer.h"

#include <QDebug>
#include <QTime>
#include <QThread>
#include <QMutexLocker>

extern const int DataSize;
extern char buffer[];
extern const int BufferSize;
extern QMutex mutex;
extern int locx;

void Producer::run()
{
//    qsrand(static_cast<uint>(QTime(0,0,0).secsTo(QTime::currentTime())));
//    for (int i = 0; i < DataSize; ++i) {
//        QMutexLocker locker(&mutex);
//        buffer[i % BufferSize] = "ACGT"[static_cast<int>(qrand()) % 4];
//    }
    QMutexLocker locker(&mutex);
    locx++;
}
