#include "mainwindow.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
    setWindowTitle(tr("可视化时钟"));
    centerWidget=new CenterWidget(this);
    setCentralWidget(centerWidget);
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeToShow()));
    timer->start(1000);
}
MainWindow::~MainWindow()
{
}
void MainWindow::timeToShow()
{
    centerWidget->update();
}
