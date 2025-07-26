#include "plate.h"
#include <QPainter>
#include <cmath>
Plate::Plate()
{
    LINE_LENGTH=9; //刻度长度
    LINE_WIDTH=2; //线宽
    GAP=10; //保留和边界的距离
    backgroundColor=Qt::lightGray;
    lineColor=Qt::black;
    numColor=Qt::red; //不同对象的颜色缺省值
}
void Plate::setRectangle(QRect rect)
{
    r=rect;
}
void Plate::draw(QPainter *p)
{
    int width=r.width();
    int height=r.height();
    int minValue=std::min(width/2,height); //长宽最小值,这里本来是width现除以二
    int x=r.x()+width/4;//这里原本除以2,现在整体左移
    int y=r.y()+height/2; //中心点 x、y 坐标
    int radius=minValue/2-GAP; //计算半径
    QRect rect(x-radius,y-radius,radius*2,radius*2);
    QPen pen(lineColor,LINE_WIDTH,Qt::SolidLine);
    QBrush brush(backgroundColor);
    p->setPen(pen);
    p->setBrush(brush); //设置背景颜色
    p->drawEllipse(rect);
    for(int i=0;i<12;++i)
    {
        double size=4;
        if(i%3==0)
        {
            size=8;
        }//这个在特定区域显示了比较长的刻度,就往这里添加元素
        drawMark(p,x,y,radius,size,i);
    }//注意到这里是搞刻度线的,应该差不多的逻辑添加刻度值
    QFont font;
    font.setPointSize(25);
    p->setPen(numColor);
    p->setFont(font);
    p->drawText(x-7.5,y-radius+25,"0");
    p->drawText(x+radius-25,y+7.5,"3");
    p->drawText(x-7.5,y+radius,"6");
    p->drawText(x-radius,y+7.5,"9");//加加减减主要是手动调整
//还有刻度值
}
void Plate::drawMark(QPainter *p,int x,int y,int radius, int size,int index)
{
    double angle=90;
    angle-=index*30;
    const double PI=3.14159;
    double x1=x+radius*std::cos(PI*angle/180);
    double y1=y-radius*std::sin(PI*angle/180);
    radius-=size;
    double x2=x+radius*std::cos(PI*angle/180);
    double y2=y-radius*std::sin(PI*angle/180);
    p->drawLine(x1, y1, x2, y2);
}
void Plate::draw2(QPainter *p)
{
    int width=r.width();
    int height=r.height();
    int minValue=std::min(width/2,height); //长宽最小值,这里本来是width现除以二
    int x=(r.x()+width/4)*3;//这里原本除以2,现在整体右移
    int y=r.y()+height/2; //中心点 x、y 坐标
    int radius=minValue/2-GAP; //计算半径
    QRect rect(x-radius,y-radius,radius*2,radius*2);
    QPen pen(lineColor,LINE_WIDTH,Qt::SolidLine);
    QBrush brush(backgroundColor);
    p->setPen(pen);
    p->setBrush(brush); //设置背景颜色
    p->drawEllipse(rect);
    for(int i=0;i<12;++i)
    {
        double size=4;
        if(i%3==0)
        {
            size=8;
        }//这个在特定区域显示了比较长的刻度,就往这里添加元素
        drawMark(p,x,y,radius,size,i);
    }//注意到这里是搞刻度线的,应该差不多的逻辑添加刻度值
    QFont font;
    font.setPointSize(25);
    p->setPen(numColor);
    p->setFont(font);
    p->drawText(x-7.5,y-radius+25,"0");
    p->drawText(x+radius-25,y+7.5,"3");
    p->drawText(x-7.5,y+radius,"6");
    p->drawText(x-radius,y+7.5,"9");//加加减减主要是手动调整
//还有刻度值
}
void Plate::setBackgroundColor(QColor color)
{
    backgroundColor=color;
}
void Plate::setLineColor(QColor color)
{
    lineColor=color;
}
void Plate::setNumColor(QColor color)
{
    numColor=color;
}
