// QtThread01 -- simple threaded GUI example
// This program should display a window with a circle that gradually moves
// from left to right.  Two worker threads "fight" over the x location locx, with
// one of the workers steadily "winning."  The purpose of this app is to demonstrate
// a simple example of how threading can work to take advantage of multiple cpu cores.

// It should be noted that we are not killing the threads properly: closing the window
// by clicking the X button on the window while shutdowncouner < shutdowncountmax does
// not send any cleanup signal or anything to the threads, so they do not end gracefully
// and you will get "QThread: Destroyed while thread is still running" in app output.
// Don't do it this way in production.

// This app is copyright 2018 inhabited.systems all rights reserved.

#include "mainwindow.h"
#include "ui_mainwindow.h"

extern QMutex mutex;
extern qreal locx;
extern qreal locy;
extern int shutdowncounter;
extern int shutdowncountmax;

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

    QPen mypen;
    QBrush mybrush;
    mypen.setColor(QColor(Qt::transparent));
    mypen.setWidth(1);
    mypen.setStyle(Qt::PenStyle(1));
    mybrush.setColor(QColor(0,0,0));

    mGraphicsScene = new QGraphicsScene(parent);
    mGraphicsView = new QGraphicsView(mGraphicsScene);
    mEllipseItem = new QGraphicsEllipseItem(0,0,mCircleSize,mCircleSize);

    // set up the view, centering it in the window
    mGraphicsView->setGeometry(0,0,mSceneWidth,mSceneHeight);

    QLayout *mylayout = new QHBoxLayout();
    centralWidget->setLayout(mylayout);
    mylayout->addWidget(mGraphicsView);

    QGraphicsRectItem *rect_item1 = mGraphicsScene->addRect(0, 0, mSceneWidth, mSceneHeight);
    rect_item1->setBrush(QColor(240,220,180)); // light tan
    rect_item1->setPen(mypen);

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
    delete ui;
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
    shutdowncounter++;
    //qDebug() << "(mainwindow)" << __FUNCTION__ << "locx:" << locx << "shutdowncounter: " << shutdowncounter << "shutdowncountmax:" << shutdowncountmax;
    mGraphicsScene->advance();
}

void MainWindow::updatecircle()
{
    if (mEllipseItem == nullptr) return;
    //qDebug() << "(mainwindow)" << __FUNCTION__ << "locx:" << locx << "shutdowncounter: " << shutdowncounter << "shutdowncountmax:" << shutdowncountmax;
    mEllipseItem->setX(locx);
}
