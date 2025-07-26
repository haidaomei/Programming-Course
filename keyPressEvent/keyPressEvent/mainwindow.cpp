#include "mainwindow.h"
#include <QPainter>
#include <QStatusBar>
MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
    setWindowTitle("Key Detection");
    keyText="Press Any Key...";
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    keyText=QString("Key:%1").arg(event->text()).arg(event->key(), 0, 16);
    statusBar()->showMessage(keyText);
    update();
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawText(rect(),keyText);
}
