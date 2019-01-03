#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //初始化
    thread=new myThread;
    sonThread=new QThread(this);
    thread->moveToThread(sonThread);

    //通过信号与槽调用线程处理函数
    connect(this,SIGNAL(startThread()),thread,SLOT(paintImageThread()));
    //接收到图片信号进行图片的处理
    connect(thread,SIGNAL(imageSignal(QImage)),this,SLOT(dealThreadSignal(QImage)));

    connect(this,&Widget::destroyed,this,&Widget::on_quitButton_clicked);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
         //线程启动但没有启动线程处理函数，返回信号
        sonThread->start();
        emit startThread();

}
void Widget::dealThreadSignal(QImage image)
{
    this->image=image;
    //间接调用绘图事件
    update();

}
  void Widget::paintEvent(QPaintEvent *event)
  {
      QPainter  P(this);
      P.drawImage(0,0,image);
  }

void Widget::on_quitButton_clicked()
{
    if(sonThread->isRunning())
    {
        sonThread->quit();
        sonThread->wait();

    }

}
