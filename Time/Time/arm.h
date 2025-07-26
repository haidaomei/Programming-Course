#ifndef ARM_H
#define ARM_H
#include <QRect>
#include <QColor>
class QPainter;
class Arm
{
public:
    enum class ArmType{HOUR,MINUTE,SECOND};
    Arm(ArmType t);
    void setColor(QColor c);
    void setRectangle(QRect rect);
    void draw(QPainter *p);
    void draw2(QPainter *p);
private:
    ArmType type; //指针类型
    QColor armColor; //指针的颜色
    QRect r; //外接矩形
};

#endif // ARM_H
