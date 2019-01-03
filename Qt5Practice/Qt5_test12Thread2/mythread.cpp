#include "mythread.h"
#include<QThread>
#include<QDebug>
myThread::myThread(QObject *parent) : QObject(parent)
{
      flag=false;
}
void myThread::dealThreadFun()
{
    while(!false)
    {
        QThread::sleep(1);
        emit  mySignal();
        qDebug()<<"子线程号:"<<QThread::currentThread();
        if(flag)
        {
            break;
        }
    }
}
void myThread::setFlag(bool ok)
{
    flag=ok;
}
