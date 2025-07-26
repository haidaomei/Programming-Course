#ifndef CLOCK2_H
#define CLOCK2_H
#include<QPainter>
#include"plate.h"
#include"arm.h"
class Clock2
{
public:
    Clock2();
    void draw(QPainter *p);
    void setRectangle(QRect rect);
private:
    Plate plate2;
    Arm hour2,minute2,second2;
};

#endif // CLOCK2_H
