#ifndef CONSUMER_H
#define CONSUMER_H

#include <QDebug>
#include <QTime>
#include <QThread>
#include <QMutexLocker>

class Consumer : public QThread
{
    Q_OBJECT
public:
    void run() override;

signals:
    void stringConsumed(const QString &text);

protected:
    bool finish;
};

#endif // CONSUMER_H
