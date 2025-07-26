#include "clock2.h"
#include <Qrect>
#include <QPainter>
#include "plate.h"
Clock2::Clock2():hour2(Arm::ArmType::HOUR), minute2(Arm::ArmType::MINUTE), second2(Arm::ArmType::SECOND)
{
    hour2.setColor(Qt::red);
    minute2.setColor(Qt::blue);
    second2.setColor(Qt::green);
}
void Clock2::setRectangle(QRect rect)
{
    plate2.setRectangle(rect);
    hour2.setRectangle(rect);
    minute2.setRectangle(rect);
    second2.setRectangle(rect);
}
void Clock2::draw(QPainter *p)
{
    plate2.draw2(p);
    hour2.draw2(p);
    minute2.draw2(p);
    second2.draw2(p);
}
