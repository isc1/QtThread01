#ifndef WORKER2_H
#define WORKER2_H

#include <QDebug>
#include <QTime>
#include <QThread>
#include <QMutexLocker>

class Worker2 : public QThread
{
    Q_OBJECT

public:
    void run() override;
};

#endif // PRODUCER_H
