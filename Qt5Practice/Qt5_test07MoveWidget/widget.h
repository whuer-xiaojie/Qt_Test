#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QEvent>
//#include<QRect>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void activateWindow();
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


    //void resizeEvent(QResizeEvent *);
    //void moveEvent(QMoveEvent *);
private:
    Ui::Widget *ui;
    QPoint p;
    //QRect curGemRect;
};

#endif // WIDGET_H
