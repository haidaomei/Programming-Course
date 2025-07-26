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
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    Ball ball;
    QList<Ball> balls;
    bool isDrawing;       // 是否正在绘制橡皮线
        QPoint startPoint;    // 鼠标按下起始点
        QPoint currentPoint;  // 鼠标当前点
};
#endif // RIGHTWIDGET_H
