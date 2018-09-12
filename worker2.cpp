#include "worker2.h"

extern QMutex mutex;
extern qreal locx;
extern qreal locy;
extern int shutdowncounter;

void Worker2::run()
{
    long totaliterations = 0;
    qreal mydelta = 0.0004;
    while(shutdowncounter > 0)
    {
        //qDebug() << "(worker2)" << __FUNCTION__ << "locx:" << locx << "shutdowncounter: " << shutdowncounter;

        { // Don't put stuff that blocks (like I/O) in the critical section.
            QMutexLocker locker(&mutex);
            locx += mydelta;
        } // QMutexLocker releases the mutex when it goes out of scope.

        totaliterations++;
        //usleep(1);
    }
    qreal totalmodifications = totaliterations * mydelta;
    qDebug() << "(worker2)" << __FUNCTION__ << "complete with" << totaliterations << "totaliterations, or" << totalmodifications << "unit (pixel) increments";

}
