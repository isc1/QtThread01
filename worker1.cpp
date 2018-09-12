#include "worker1.h"

extern QMutex mutex;
extern qreal locx;
extern qreal locy;
extern int shutdowncounter;
extern int shutdowncountmax;

void Worker1::run()
{
    long totaliterations;
    while(shutdowncounter > 0)
    {
        //qDebug() << "(worker1)" << __FUNCTION__ << "locx:" << locx << "shutdowncounter: " << shutdowncounter;

        { // Don't put stuff that blocks (like I/O) in the critical section.
            QMutexLocker locker(&mutex);
            locx -= 0.0001;
        } // QMutexLocker releases the mutex when it goes out of scope.

        // duuuuude.... comment the next line out and watch what happens... it changes the circle movement, EVEN THOUGH
        // IT IS NOT PART OF THE locx CALCULATIONS DURING THE ANIMATION RUNTIME... is this compiler/cpu pipeline lookahead stuff?
        // wtf?!!... okay, now I'm officially afraid of thread programming...
        totaliterations++;
        //msleep(1);
    }
    qreal totalmodifications = totaliterations * 0.0001;
    qDebug() << "(worker1)" << __FUNCTION__ << "complete with" << totaliterations << "totaliterations, or" << totalmodifications << "unit decrements";

}
