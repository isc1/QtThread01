#include "mainwindow.h"
#include <QApplication>
#include "worker1.h"
#include "worker2.h"

extern QMutex mutex;
extern qreal locx;
extern qreal locy;
extern int shutdowncounter;

QMutex mutex;

// If these don't get assigned here in main(), they are not allocated at all and don't
// exist as externs for other source files, causing build errors:
qreal locx = 0;
qreal locy = 0;
int shutdowncounter = 2000;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //qDebug() << __FUNCTION__ << " start.";

    Worker1 worker1;
    Worker2 worker2;
    worker1.start();
    worker2.start();

    w.show();
    return a.exec();
}
