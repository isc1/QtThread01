#include "worker1.h"

extern QMutex mutex;
extern qreal locx;
extern qreal locy;
extern int shutdowncounter;

void Worker1::run()
{
    long totaliterations = 0;
    qreal mydelta = 0.0002;
    while(shutdowncounter > 0)
    {
        //qDebug() << "(worker1)" << __FUNCTION__ << "locx:" << locx << "shutdowncounter: " << shutdowncounter;

        { // Don't put stuff that blocks (like I/O) in the critical section.
            QMutexLocker locker(&mutex);
            locx -= mydelta;
        } // QMutexLocker releases the mutex when it goes out of scope.

        totaliterations++;
        // if one usleep is uncommented, the circle shoots off the scene.  if both this usleep and the one in worker2
        // are uncommented, locx changes verrrry slowly... start shutdowncounter > 3000 or so with both usleeps uncommented
        // to see.
        //usleep(1);
    }
    qreal totalmodifications = totaliterations * mydelta;
    qDebug() << "(worker1)" << __FUNCTION__ << "complete with" << totaliterations << "totaliterations, or" << totalmodifications << "unit (pixel) decrements";

}
