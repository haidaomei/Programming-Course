#include "rightwidget.h"
#include <QPainter>
#include <cmath>
#include <QMouseEvent>
RightWidget::RightWidget(QWidget *parent):QWidget(parent)
{
    setMinimumSize(400,200); //制定最小尺寸
    balls.clear(); //清空后手工添加 3 个小球，用于测试
    addBall(Ball(30,20,10,10,49,Qt::red));
    addBall (Ball(56,200,10,4,39,Qt::blue));
    addBall (Ball(80,100,10,7,69,Qt::yellow));
    isDrawing = false;
}
void RightWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    for(auto& b:balls)
    {
        b.draw(&p);
    }
    // 绘制橡皮线（预览线）
        if(isDrawing) {
            p.setPen(QPen(Qt::black, 1, Qt::DashLine));
            p.drawLine(startPoint, currentPoint);

            // 在起点绘制预览小球
            p.setPen(QPen(Qt::gray, 1, Qt::SolidLine));
            p.setBrush(QBrush(Qt::lightGray));
            p.drawEllipse(startPoint, 10, 10);
        }
}
void RightWidget::updateBalls() //封装的控制小球移动的接口
{
    for(auto &b:balls)
    {
        b.setRectangle(this->geometry());
        b.move();
    }
    int i,j;
    for(i=0;i<balls.size()-1;++i)
    {
        for(j=i+1;j<balls.size();++j)
        {
            balls[i].checkCollision(balls[j]);
        }
    }
    update(); //更新窗口显示，重绘小球
}
void RightWidget::addBall(const Ball &b)
{
    balls.append(b);
}
void RightWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        startPoint = event->pos();
        currentPoint = startPoint;
        isDrawing = true;
        update();
    }
}

void RightWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (isDrawing) {
        currentPoint = event->pos();
        update();
    }
}

void RightWidget::mouseReleaseEvent(QMouseEvent *event)//这个函数有可能出现向下拉球向右走的情况 这是因为qt的坐标是向下正y不是向上 这里需要把dxdy都反转然后改变angle值
{
    if (event->button() == Qt::LeftButton && isDrawing)
    {
        QPoint endPoint = event->pos();
        isDrawing = false;
        double dx = endPoint.x() - startPoint.x();
        double dy = endPoint.y() - startPoint.y();
        double distance = std::sqrt(dx*dx + dy*dy);
        double speed = distance / 10.0;
        double angle = (std::atan2(-dy, -dx) * 180 / 3.1415926535);//注意这是弧度
        angle = fmod(angle + 360, 360);
        angle = 270 - angle;
        addBall(Ball(startPoint.x(), startPoint.y(), 10, speed, angle, Qt::green));
        update();
    }
}
