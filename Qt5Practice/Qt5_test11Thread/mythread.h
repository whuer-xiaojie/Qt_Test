#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = 0);
protected:
    //QThread 的虚函数
    void run();

signals:
    void isDone();

public slots:
};

#endif // MYTHREAD_H
