#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QPixmap>
#include<QPen>
#include<QBrush>
#include<QLabel>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setMaximumSize(1000,540);
    this->setMinimumSize(1000,540);


}

Widget::~Widget()
{
    delete ui;
}
 void Widget::paintEvent(QPaintEvent *event)
 {
     QPainter P(this);
     P.drawPixmap(0,0,width(),height(),QPixmap("../backImage/image2.jpg"));
     QPen pen;
     pen.setWidth(2);
     pen.setColor(Qt::red);
     P.setPen(pen);
     for(int x=0;x<=700;x+=35)
     {
         P.drawLine(x,0,x,540);
     }
     for(int y=0;y<=540;y+=30)
    {
         P.drawLine(0,y,700,y);
     }





 }
