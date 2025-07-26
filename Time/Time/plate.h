#ifndef PLATE_H
#define PLATE_H
#include <QRect>
#include <QColor>
class QPainter;
class Plate
{
public:
    Plate();
    void setRectangle(QRect rect);
    void draw(QPainter *p);
    void draw2(QPainter *p);
    void drawMark(QPainter *p,int x,int y,int radius, int size,int index);
    //x,y 为窗口中心点坐标，radius 为半径，
    // size 为刻度大小，index 为第几个刻度
    void setBackgroundColor(QColor color);
    void setLineColor(QColor color);
    void setNumColor(QColor color);
private:
    int LINE_LENGTH; //刻度长度
    int LINE_WIDTH; //线宽
    int GAP; //保留和边界的距离
    QColor backgroundColor;
    QColor lineColor;
    QColor numColor; //不同对象的颜色
    QRect r; //控制表盘大小的外接矩形
};

#endif // PLATE_H
