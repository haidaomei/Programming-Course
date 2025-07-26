#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H
#include <QWidget>
#include "ball.h"
#include <QList>
class RightWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RightWidget(QWidget *parent=0);
    void paintEvent(QPaintEvent *);
    void updateBalls(); //移动小球的接口
    void addBall(const Ball& b); //添加小球的接口
signals:
public slots:
private:
    Ball ball;
    QList<Ball> balls;
};
#endif // RIGHTWIDGET_H
