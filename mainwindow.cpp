#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

extern const int DataSize;
extern char buffer[];
extern const int BufferSize;
extern QMutex mutex;
extern qreal locx;
extern bool shutdownnow;
extern int shutdowncounter;
extern int shutdowncountmax;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
    //, ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    setGeometry(0,0,800,600);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    //int myi=0;
//    shutdownnow = FALSE;
//    shutdowncounter=0;
//    shutdowncountmax=100000;

    QPen mypen;
    QBrush mybrush;
    mypen.setColor(QColor(Qt::transparent));
    mypen.setWidth(1);
    mypen.setStyle(Qt::PenStyle(1));
    mybrush.setColor(QColor(0,0,0));


    // why does the next line cause runtime to crash?
    mGraphicsScene = new QGraphicsScene(parent);
    mGraphicsView = new QGraphicsView(mGraphicsScene);
    mEllipseItem = new QGraphicsEllipseItem(0,0,10,10);


    // set up the view, centering it in the window
    mGraphicsView->setGeometry(0,0,800,600);
    mGraphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    mGraphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    QLayout *mylayout = new QHBoxLayout();
    centralWidget->setLayout(mylayout);
    mylayout->addWidget(mGraphicsView);

    mGraphicsScene->addItem(mEllipseItem);
    mGraphicsScene->addEllipse(10,10,10,10,mypen,mybrush);

    startGameLoopTimer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGameLoopTimer()
{
    // associate the signal timeout() to the slot gameTick(), and start our update timer
    QObject::connect(&mGameLoopTimer, SIGNAL(timeout()), this, SLOT(gameLoopTick()));
    mGameLoopTimer.start(5);

    qDebug() << __FUNCTION__ << " complete.";
}

void MainWindow::gameLoopTick()
{

    updatecircle();
    shutdowncounter++;
    //qDebug() << "(mainwindow)  shutdowncounter: " << shutdowncounter << "   shutdowncountmax:" << shutdowncountmax;


    mGraphicsScene->advance();

}

void MainWindow::updatecircle()
{
    if (mEllipseItem == nullptr) return;

    //qDebug() << "At count " << shutdowncounter << " setting ellipse x: " <<locx;
    mEllipseItem->setX(locx);
}
