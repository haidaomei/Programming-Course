#ifndef CLOCK_H
#define CLOCK_H
#include "arm.h"
#include "plate.h"
class Clock
{
public:
    Clock();
    void draw(QPainter *p);
    void setRectangle(QRect rect);
private:
    Plate plate;
    Arm hour,minute,second;
};

#endif // CLOCK_H
