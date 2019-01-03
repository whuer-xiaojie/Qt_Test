#include "widget.h"
#include "ui_widget.h"
#include<QString>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->timeId1=this->startTimer(1000);//每一秒启动一次计时器

    this->timeId2=this->startTimer(500);//每500毫秒启动一次计时器

}

Widget::~Widget()
{
    delete ui;
}
void Widget::timerEvent(QTimerEvent *event)
{

    if(event->timerId()==timeId1)
    {
           static int sec=0;
           ui->lineEdit->setText(QString("%1").arg(sec++));
           if(sec>10)
           {
               this->killTimer(this->timeId1);
           }
    }
    else
    {
        static int sed=0;
        ui->lineEdit_2->setText(QString("%1").arg(sed++));
    }

}

/*
void Widget::enterEvent(QEvent *event)
{

    ui->widget->setStyleSheet("QWidget{"
                        "border-image:url(:/new/prefix1/image/fc8180442b046bec676f11173a28cccb.jpg);"
                        "}");

}

void Widget::leaveEvent(QEvent *event)
{
    ui->widget->setStyleSheet("QWidget{"
                        "border-image:url(:/new/prefix1/image/aa5805a64691491a2edeefd750e3e00a.jpg);"
                        "}");

}
*/



