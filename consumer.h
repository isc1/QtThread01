#ifndef CONSUMER_H
#define CONSUMER_H

#include <QDebug>
#include <QTime>
#include <QThread>
#include <QMutexLocker>

//extern const int DataSize;
//extern char buffer[];
//extern const int BufferSize;
//extern QMutex mutex;

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
