#include "mythread.h"

myThread::myThread(QObject *parent) : QThread(parent)
{

}
void myThread::run()
{
    //很复杂的数据处理需要2秒
    QThread::sleep(2);
    emit isDone();

}
