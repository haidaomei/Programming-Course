#include "arm.h"
#include <QTime>
#include <QPen>
#include <QPainter>
#include <cmath>
Arm::Arm(Arm::ArmType t)
{
    type=t;
    armColor=Qt::blue;
}
void Arm::setColor(QColor c)
{
    armColor=c;
}
void Arm::setRectangle(QRect rect)
{
    r=rect;
}
void Arm::draw(QPainter *p)
{
    QTime time=QTime::currentTime(); //获取系统当前时间
    int h=time.hour()%12;
    int m=time.minute();
    int s=time.second();
    double angle=90,size=0;
    double x=r.x()+r.width()/4;//这里原本除以2
    double y=r.y()+r.height()/2; //计算中心点
    size=std::min(r.width()/2, r.height()/2);
    switch(type)
    { //根据指针类型、时间计算角度和指针长度
    case ArmType::HOUR:
        angle=90-h*30-m/2;
        size*=18.0/30;
        break;
    case ArmType::MINUTE:
        angle=90-m*6-s/10;
        size*=20.0/30;
        break;
    case ArmType::SECOND:
        angle=90-s*6;
        size*=23.0/30;
        break;
    }
    QPen pen(armColor,2,Qt::SolidLine);
    p->setPen(pen);
    const double PI=3.14159;
    QBrush brush(armColor);
    p->setBrush(brush);
    int point[8]; //4 个点的坐标序列构成的数组，每个点2 个坐标
    double angle1=angle-90;
    double size1=size/10;
    double size2=size/5;
    double dy1=size1*std::sin(PI*angle1/180);
    double dx1=size1*std::cos(PI*angle1/180);
    point[0]=(int)(x+dx1);
    point[1]=(int)(y-dy1);
    double dy2=size*std::sin(PI*angle/180);
    double dx2=size*std::cos(PI*angle/180);
    point[2]=(int)(x+dx2);
    point[3]=(int)(y-dy2);
    point[4]=(int)(x-dx1);
    point[5]=(int)(y+dy1);
    double dy3=size2*std::sin(PI*angle/180);
    double dx3=size2*std::cos(PI*angle/180);
    point[6]=(int)(x-dx3);
    point[7]=(int)(y+dy3);//因为四个点8个x和y所以是8个元素
    QPolygon polygon(4); //构造 4 边形，对应 4 个顶点
    polygon.setPoints(4,point); //设置 4 个顶点的坐标
    p->drawPolygon(polygon); //绘制 4 边形
    const int radius=5;
    QPen penCenter(Qt::black);
    QBrush brushCenter(Qt::black);
    p->setPen(penCenter);
    p->setBrush(brushCenter);
    p->drawEllipse(x-radius,y-radius,radius*2,radius*2); //绘制中心
}
void Arm::draw2(QPainter *p)
{
    QTime time=QTime::currentTime(); //获取系统当前时间
    int h=(time.hour()%12)-7;
    int m=time.minute();
    int s=time.second();
    double angle=90,size=0;
    double x=(r.x()+r.width()/4)*3;//这里原本除以2
    double y=r.y()+r.height()/2; //计算中心点
    size=std::min(r.width()/2, r.height()/2);
    switch(type)
    { //根据指针类型、时间计算角度和指针长度
    case ArmType::HOUR:
        angle=90-h*30-m/2;
        size*=18.0/30;
        break;
    case ArmType::MINUTE:
        angle=90-m*6-s/10;
        size*=20.0/30;
        break;
    case ArmType::SECOND:
        angle=90-s*6;
        size*=23.0/30;
        break;
    }
    QPen pen(armColor,2,Qt::SolidLine);
    p->setPen(pen);
    const double PI=3.14159;
    QBrush brush(armColor);
    p->setBrush(brush);
    int point[8]; //4 个点的坐标序列构成的数组，每个点2 个坐标
    double angle1=angle-90;
    double size1=size/10;
    double size2=size/5;
    double dy1=size1*std::sin(PI*angle1/180);
    double dx1=size1*std::cos(PI*angle1/180);
    point[0]=(int)(x+dx1);
    point[1]=(int)(y-dy1);
    double dy2=size*std::sin(PI*angle/180);
    double dx2=size*std::cos(PI*angle/180);
    point[2]=(int)(x+dx2);
    point[3]=(int)(y-dy2);
    point[4]=(int)(x-dx1);
    point[5]=(int)(y+dy1);
    double dy3=size2*std::sin(PI*angle/180);
    double dx3=size2*std::cos(PI*angle/180);
    point[6]=(int)(x-dx3);
    point[7]=(int)(y+dy3);//因为四个点8个x和y所以是8个元素
    QPolygon polygon(4); //构造 4 边形，对应 4 个顶点
    polygon.setPoints(4,point); //设置 4 个顶点的坐标
    p->drawPolygon(polygon); //绘制 4 边形
    const int radius=5;
    QPen penCenter(Qt::black);
    QBrush brushCenter(Qt::black);
    p->setPen(penCenter);
    p->setBrush(brushCenter);
    p->drawEllipse(x-radius,y-radius,radius*2,radius*2); //绘制中心
}
