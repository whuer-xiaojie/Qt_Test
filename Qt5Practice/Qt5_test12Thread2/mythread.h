#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class myThread : public QObject
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = 0);

private:
    bool flag;

signals:
    //线程信号
    void mySignal();
public slots:
    //线程处理函数
    void dealThreadFun();
    //flag赋值函数
    void setFlag(bool  ok=true);
};

#endif // MYTHREAD_H
