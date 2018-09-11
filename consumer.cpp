#include "consumer.h"

#include <QDebug>
#include <QTime>
#include <QThread>
#include <QMutexLocker>

extern const int DataSize;
extern char buffer[];
extern const int BufferSize;
extern QMutex mutex;

void Consumer::run()
{
    for (int i = 0; i < DataSize; ++i) {
        QMutexLocker locker(&mutex);
        //fprintf(stderr, "%c", buffer[i % BufferSize]);
        qDebug() << buffer[i%BufferSize];
    }
    //fprintf(stderr, "\n");
}
