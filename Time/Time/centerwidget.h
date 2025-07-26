#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H
#include <QWidget>
#include "clock.h"
#include "clock2.h"
class CenterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CenterWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
signals:
public slots:
private:
    Clock clock;
    Clock2 clock2;
};
#endif // CENTERWIDGET_H
