#include "mainwindow.h"
#include <QApplication>
#include "consumer.h"
#include "producer.h"

extern const int DataSize;
extern const int BufferSize;
extern char buffer[];
extern QMutex mutex;
extern qreal locx;
extern bool shutdownnow;
extern int shutdowncounter;
extern int shutdowncountmax;


extern const int DataSize = 30;
extern const int BufferSize = 5;
char buffer[BufferSize];
qreal locx = 200;
QMutex mutex;

bool shutdownnow = FALSE;
int shutdowncounter = 0;
int shutdowncountmax = 100000;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qDebug() << "Here in main";

    //for(int i=0; i< DataSize; i++) buffer[i] = 'A';

    Producer producer;
    Consumer consumer;
    producer.start();
    consumer.start();

//    consumer.wait();
//    producer.wait();

    w.show();
    return a.exec();
}
