#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPaintEvent>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    //如果在窗口绘图，必须在绘图事件里实现
    //绘图事件内部自动调用，窗口需要重绘的时候（窗口状态改变，大小等）
    void paintEvent(QPaintEvent *event);


private:
    Ui::Widget *ui;

};

#endif // WIDGET_H
