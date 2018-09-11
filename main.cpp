#include "mainwindow.h"
#include <QApplication>
#include "consumer.h"
#include "producer.h"

extern const int DataSize;
extern const int BufferSize;
extern char buffer[];
extern QMutex mutex;

extern const int DataSize = 30;
extern const int BufferSize = 5;
char buffer[BufferSize];
int locx = 0;
QMutex mutex;

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
    producer.wait();
    consumer.wait();
    w.show();

    return a.exec();
}
