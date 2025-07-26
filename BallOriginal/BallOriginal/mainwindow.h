#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QSplitter>
#include <QTimer>
#include "leftwidget.h"
#include "rightwidget.h"
class MainWindow:public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent=0);
    ~MainWindow();
    void stopTimer(); //停止定时器的接口
    void resumeTimer(); //重启定时器的接口
    RightWidget* getRightWidget(){return right;}
protected slots:
    void timeToShow();
private:
    LeftWidget *left;
    RightWidget *right;
    QSplitter *splitter;
    QTimer *timer;
};
#endif // MAINWINDOW_H
