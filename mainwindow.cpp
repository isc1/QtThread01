#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int myi=0;

    QPen mypen;
    QBrush mybrush;
    mypen.setColor(QColor(Qt::transparent));
    mypen.setWidth(1);
    mypen.setStyle(Qt::PenStyle(1));
    mybrush.setColor(QColor(0,0,0));

    mEllipseItem = new QGraphicsEllipseItem(0,0,10,10);

    // why does the next line cause runtime to crash?
    mGraphicsScene->addItem(mEllipseItem);
    //mGraphicsScene->addEllipse(10,10,10,10,mypen,mybrush);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGameLoopTimer()
{
    // associate the signal timeout() to the slot gameTick(), and start our update timer
    QObject::connect(&mGameLoopTimer, SIGNAL(timeout()), this, SLOT(gameLogicTick()));
    mGameLoopTimer.start(5);

    qDebug() << __FUNCTION__ << " complete.";
}

void MainWindow::gameLoopTick()
{

    updatecircle();

    mGraphicsScene->advance();

}

void MainWindow::updatecircle()
{


}
