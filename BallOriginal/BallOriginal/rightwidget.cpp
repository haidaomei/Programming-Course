#include "rightwidget.h"
#include <QPainter>
RightWidget::RightWidget(QWidget *parent):QWidget(parent)
{
    setMinimumSize(400,200); //制定最小尺寸
    balls.clear(); //清空后手工添加 3 个小球，用于测试
    addBall(Ball(30,20,10,10,49,Qt::red));
    addBall (Ball(56,200,10,4,39,Qt::blue));
    addBall (Ball(80,100,10,7,69,Qt::yellow));
}
void RightWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    for(auto& b:balls)
    {
        b.draw(&p);
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
