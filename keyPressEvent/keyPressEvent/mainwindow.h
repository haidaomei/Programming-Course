#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QKeyEvent>
class MainWindow:public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent=nullptr);
protected:
    void keyPressEvent(QKeyEvent *event)override;
    void paintEvent(QPaintEvent *event)override;
private:
    QString keyText;
};
#endif // MAINWINDOW_H
