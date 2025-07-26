#include "centerwidget.h"
#include <QPainter>
CenterWidget::CenterWidget(QWidget *parent):QWidget(parent)
{
    setMinimumSize(400,300);
}
void CenterWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    clock.setRectangle(this->geometry());
    clock.draw(&p);
    clock2.setRectangle(this->geometry());
    clock2.draw(&p);
}
