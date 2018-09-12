#ifndef WORKER1_H
#define WORKER1_H

#include <QDebug>
#include <QTime>
#include <QThread>
#include <QMutexLocker>

class Worker1 : public QThread
{
    Q_OBJECT

public:
    void run() override;

};

#endif // CONSUMER_H
