#include "mythread.h"
#include<QPen>
#include<QBrush>
myThread::myThread(QObject *parent) : QObject(parent)
{

}
void myThread::paintImageThread()
{
    QImage image(400,400,QImage::Format_ARGB32);
    QPainter painter(&image);
    //painter.drawImage(0,0,QImage("../backImage/image2"));

    //设置画笔
    QPen pen;
    pen.setWidth(5);
    painter.setPen(pen);

    //设置样式
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    //产生随机点
    QPoint P[]=
    {
        QPoint(qrand()%400,qrand()%400),
        QPoint(qrand()%400,qrand()%400),
        QPoint(qrand()%400,qrand()%400),
        QPoint(qrand()%400,qrand()%400),
        QPoint(qrand()%400,qrand()%400)

    };
    //绘制多边形
    painter.drawPolygon(P,5);
    //触发信号，返回图片
    emit imageSignal( image);
}
