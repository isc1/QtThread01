#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int mSceneWidth;
    int mSceneHeight;
    QGraphicsScene *mGraphicsScene;
    QGraphicsView *mGraphicsView;
    QGraphicsEllipseItem *mEllipseItem;
    qreal mCircleSize;
    long mAppLoopUpdateInterval;
    QTimer mAppLoopTimer;
    void startAppLoopTimer();
    void updatecircle();

private:
    Ui::MainWindow *ui;

private slots:
    void appLoopTick();
};

#endif // MAINWINDOW_H
