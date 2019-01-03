#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //初始化
    thread=new myThread;
    sonThread=new QThread(this);
    //把自定义线程移到子线程
    thread->moveToThread(sonThread);
    //收到线程启动信号调用线程处理函数
    connect(this,SIGNAL(startThread()),thread,SLOT(dealThreadFun()));
    qDebug()<<"主线程号:"<<QThread::currentThread();
    //收到线程处理函数信号，调用线程信号处理槽函数
    connect(thread,SIGNAL(mySignal()),this,SLOT(dealMySignal()));
    //窗口关闭就关闭线程
    connect(this,&Widget::destroyed,this,&Widget::on_stopButton_clicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    if(sonThread->isRunning())
    {
        return;
    }
    //启动子线程，发射线程启动信号
    thread->setFlag(false);
    sonThread->start();
    emit startThread();
}
void Widget::dealMySignal()
{
    static int i=0;
    i++;
    ui->lcdNumber->display(i);
}

void Widget::on_stopButton_clicked()
{
    if(sonThread->isRunning()==false)
        return;
    thread->setFlag(true);
    sonThread->quit();
    sonThread->wait();
    //delete thread;
    //delete sonThread;
}
