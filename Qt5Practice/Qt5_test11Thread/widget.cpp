#include "widget.h"
#include "ui_widget.h"
#include<QThread>
#include<QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    myTimer=new QTimer(this);
    //计时器连接
    connect(myTimer,&QTimer::timeout,this,&Widget::dealTimeout);
    thread=new myThread(this);
    //线程完成
    connect(thread,&myThread::isDone,this,&Widget::dealisDone);
    //关闭线程
    connect(this,&Widget::destroyed,this,&Widget::closeThread);
}

Widget::~Widget()
{
    delete ui;
}
 void Widget::dealTimeout()
 {
    static  int i=0;
     i++;
     ui->lcdNumber->display(i);

 }

void Widget::on_pushButton_clicked()
{
    if(myTimer->isActive())
    {
        return;
    }
    else
     {
        //启动计时器
        myTimer->start(1000);
    }

      //QThread::sleep(2);
      //myTimer->stop();
      //qDebug()<<"over";

    //启动线程，处理数据
    thread->start();


}
void Widget::dealisDone()
{
    qDebug()<<"deal finish";
    myTimer->stop();
}
void Widget::closeThread()
{
    thread->quit();
    thread->wait();
}
