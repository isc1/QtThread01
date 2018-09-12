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

signals:
    //void stringConsumed(const QString &text);

protected:
    //bool finish;
};

#endif // CONSUMER_H
