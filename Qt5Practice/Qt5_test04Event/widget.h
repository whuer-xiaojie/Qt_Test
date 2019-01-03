#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimerEvent>
//#include<QTimer>
#include<QEvent>

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
    void timerEvent(QTimerEvent *event);
    //void enterEvent(QEvent *event);
    //void leaveEvent(QEvent *event);

private:
    Ui::Widget *ui;
    int timeId1;
    int timeId2;

};

#endif // WIDGET_H
