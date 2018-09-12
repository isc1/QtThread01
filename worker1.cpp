#include "worker1.h"

extern QMutex mutex;
extern qreal locx;
extern qreal locy;
extern int shutdowncounter;
extern int shutdowncountmax;

void Worker1::run()
{
    while(shutdowncounter < shutdowncountmax)
    {
        //qDebug() << "(worker1)" << __FUNCTION__ << "locx:" << locx << "shutdowncounter: " << shutdowncounter << "shutdowncountmax:" << shutdowncountmax;

        // Don't put blocking stuff in the critical section.
        {
            QMutexLocker locker(&mutex);
            locx -= 0.0001;
        } // QMutexLocker releases the mutex when it goes out of scope.

        //msleep(1);
    }
    qDebug() << "(worker1)" << __FUNCTION__ << "complete";

}
