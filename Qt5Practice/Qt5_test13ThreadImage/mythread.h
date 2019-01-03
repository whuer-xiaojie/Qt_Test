#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include<QImage>
#include<QPainter>
#include<QPen>

class myThread : public QObject
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = 0);

signals:
    //返回绘制的图片
    void imageSignal(QImage image);

public slots:
    //绘制图片，线程处理函数
    void paintImageThread();
};

#endif // MYTHREAD_H
