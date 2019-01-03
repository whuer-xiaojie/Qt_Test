#ifndef MALABEL_H
#define MALABEL_H

#include <QLabel>

class MyLabel : public QLabel//自定义子控件
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
protected:
    void mousePressEvent(QMouseEvent *event);//鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *event);//鼠标放开事件
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动事件

signals:

public slots:
};

#endif // MALABEL_H
