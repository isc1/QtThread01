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
    QTimer mGameLoopTimer;
    void startGameLoopTimer();
    QGraphicsScene *mGraphicsScene;
    QGraphicsView *mGraphicsView;
    QGraphicsEllipseItem *mEllipseItem;
    void updatecircle();


private:
    Ui::MainWindow *ui;

private slots:
    void gameLoopTick();
};

#endif // MAINWINDOW_H
