#include "worker1.h"

extern QMutex mutex;
extern qreal locx;
extern qreal locy;
extern int shutdowncounter;
extern int shutdowncountmax;

void Worker1::run()
{
    long totaliterations = 0;
    while(shutdowncounter > 0)
    {
        //qDebug() << "(worker1)" << __FUNCTION__ << "locx:" << locx << "shutdowncounter: " << shutdowncounter;

        { // Don't put stuff that blocks (like I/O) in the critical section.
            QMutexLocker locker(&mutex);
            locx -= 0.0001;
        } // QMutexLocker releases the mutex when it goes out of scope.

        // if you comment the next line out, it changes the way the circle moves, which is interesting
        //totaliterations++;
        //msleep(1);
    }
    qreal totalmodifications = totaliterations * 0.0001;
    qDebug() << "(worker1)" << __FUNCTION__ << "complete with" << totaliterations << "totaliterations, or" << totalmodifications << "unit decrements";

}
