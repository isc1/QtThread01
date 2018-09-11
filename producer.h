#ifndef PRODUCER_H
#define PRODUCER_H

#include <QThread>

class Producer : public QThread
{
    Q_OBJECT

public:
    //Producer(int mydatasize);
    void run() override;
};

#endif // PRODUCER_H
