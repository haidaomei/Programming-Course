#include "clock.h"
#include <Qrect>
#include <QPainter>
#include "plate.h"
Clock::Clock():hour(Arm::ArmType::HOUR), minute(Arm::ArmType::MINUTE), second(Arm::ArmType::SECOND)
{
    hour.setColor(Qt::red);
    minute.setColor(Qt::blue);
    second.setColor(Qt::green);
}
void Clock::setRectangle(QRect rect)
{
    plate.setRectangle(rect);
    hour.setRectangle(rect);
    minute.setRectangle(rect);
    second.setRectangle(rect);
}
void Clock::draw(QPainter *p)
{
    plate.draw(p);
    hour.draw(p);
    minute.draw(p);
    second.draw(p);
}
