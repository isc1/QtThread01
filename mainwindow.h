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
    int mWindowOriginX;
    int mWindowOriginY;
    int mWindowWidth;
    int mWindowHeight;
    int mSceneWidth;
    int mSceneHeight;
    int mWindowSceneXOffset;
    int mWindowSceneYOffset;
    int mWindowViewOffset;
    QGraphicsScene *mGraphicsScene;
    QGraphicsView *mGraphicsView;
    QGraphicsEllipseItem *mEllipseItem;
    qreal mCircleSize;
    long mGameLogicUpdateInterval;
    QTimer mAppLoopTimer;
    void startAppLoopTimer();
    void updatecircle();

private:
    Ui::MainWindow *ui;

private slots:
    void appLoopTick();
};

#endif // MAINWINDOW_H
