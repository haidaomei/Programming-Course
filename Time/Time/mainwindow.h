#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "centerwidget.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void timeToShow();
private:
    CenterWidget *centerWidget;
};

#endif // MAINWINDOW_H
