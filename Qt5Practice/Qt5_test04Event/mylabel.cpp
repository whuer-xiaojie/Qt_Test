#include "mylabel.h"
#include<QMouseEvent>
#include<QDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //this->setMouseTracking(true);
}
void MyLabel:: mousePressEvent(QMouseEvent *event)
{
    int x=event->x();
    int y=event->y();
    QString text=QString("<h1>Mouse Press:(%1,%2)</h1>").arg(x).arg(y);
    //QString text=QString("<center><h1>Mouse Pressed:(%1,%2)</h1></center>").arg(x).arg(y);//在窗口中间显示并加粗
    this->setText(text);
    if(event->button()==Qt::LeftButton)//鼠标被按下的键是否为左键
    {
        qDebug()<<"left";
    }
    if(event->button()==Qt::RightButton)
    {
        qDebug()<<"right";
    }
    if(event->button()==Qt::MidButton)
    {
        qDebug()<<"Mid";
    }
}

void MyLabel:: mouseReleaseEvent(QMouseEvent *event)
{
    QString text=QString("<h1>Mouse Release:(%1,%2)</h1>").arg(event->x()).arg(event->y());
    this->setText(text);
}

void MyLabel:: mouseMoveEvent(QMouseEvent *event)
{
    QString text=QString("<h1>Mouse Move:(%1,%2)</h1>").arg(event->x()).arg(event->y());
    this->setText(text);
}
