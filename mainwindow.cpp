// QtThread01 -- simple threaded GUI example
// see README.md for description.

// This code was written on Qt 5.11.1 on Windows 10.  It may run on OS X and Linux with
// modifications but we haven't done that.

// This code is copyright 2018 inhabited.systems, and is shared under the MIT license.
// (See file MIT-License.txt)  This code is unsupported.

#include "mainwindow.h"

extern QMutex mutex;
extern qreal locx;
extern qreal locy;
extern int shutdowncounter;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
  , mSceneWidth(600)
  , mSceneHeight(600)
  , mGraphicsScene(Q_NULLPTR)
  , mGraphicsView(Q_NULLPTR)
  , mEllipseItem(Q_NULLPTR)
  , mCircleSize(100)
  , mAppLoopUpdateInterval(5) // in milliseconds
{
    setGeometry(0,0,mSceneWidth,mSceneHeight);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    mGraphicsScene = new QGraphicsScene(parent);
    mGraphicsView = new QGraphicsView(mGraphicsScene);
    mGraphicsView->setGeometry(0,0,mSceneWidth,mSceneHeight);

    QLayout *mylayout = new QHBoxLayout();
    centralWidget->setLayout(mylayout);
    mylayout->addWidget(mGraphicsView);

    QPen mypen;
    QBrush mybrush;
    mypen.setColor(QColor(Qt::transparent));
    mypen.setWidth(1);
    mypen.setStyle(Qt::PenStyle(1));
    mybrush.setColor(QColor(0,0,0));

    //set a background color
    QGraphicsRectItem *rect_item1 = mGraphicsScene->addRect(0, 0, mSceneWidth, mSceneHeight);
    rect_item1->setBrush(QColor(255, 243, 230)); // light tan
    //rect_item1->setPen(mypen);
    QGraphicsRectItem *rect_item2 = mGraphicsScene->addRect(mSceneWidth/4+mCircleSize/1.35, mSceneHeight/4+mCircleSize/1.35, mSceneWidth/4, mSceneHeight/4);


    mEllipseItem = new QGraphicsEllipseItem(0,0,mCircleSize,mCircleSize);
    mGraphicsScene->addItem(mEllipseItem);
    locx = 30;
    locy = (mSceneHeight/2) - (mCircleSize/2);
    //qDebug() << "add circle at locx " << locx;
    mGraphicsScene->addEllipse(locx,locy,mCircleSize,mCircleSize,mypen,mybrush);
    // For some reason, the previous addEllipse doesn't seem to setX,setY to locx,locy
    // so we have to do it explicitly:
    mEllipseItem->setX(locx);
    mEllipseItem->setY(locy);

    startAppLoopTimer();
}

MainWindow::~MainWindow()
{
    // I set this to try to tell threads to quit, but it doesn't work.  We need to catch the
    // user clicking the X button to close the window, and make the threads quit from that.
    // try https://stackoverflow.com/questions/26181486/c-application-does-not-kill-all-processes-on-exit#26181776
    shutdowncounter = 0;
}

void MainWindow::startAppLoopTimer()
{
    // associate the signal timeout() to the slot appLoopTick(), and start our update timer
    QObject::connect(&mAppLoopTimer, SIGNAL(timeout()), this, SLOT(appLoopTick()));
    mAppLoopTimer.start(5);
    //qDebug() << __FUNCTION__ << "complete.";
}

void MainWindow::appLoopTick()
{
    updatecircle();
    shutdowncounter--;
    //qDebug() << "(mainwindow)" << __FUNCTION__ << "locx:" << locx << "shutdowncounter: " << shutdowncounter;
    mGraphicsScene->advance();
}

void MainWindow::updatecircle()
{
    if (mEllipseItem == nullptr) return;
    //qDebug() << "(mainwindow)" << __FUNCTION__ << "locx:" << locx << "shutdowncounter: " << shutdowncounter;
    mEllipseItem->setX(locx);
}
