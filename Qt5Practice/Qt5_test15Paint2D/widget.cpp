#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QLinearGradient>
#include<QRadialGradient>
#include<QConicalGradient>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *event)
{
    //线性渐变
    QLinearGradient linearGradient(QPointF(10,20),QPointF(20,100));
    linearGradient.setColorAt(0,Qt::yellow);
    linearGradient.setColorAt(0.5,Qt::red);
    linearGradient.setColorAt(1,Qt::green);
   linearGradient.setSpread(QGradient::RepeatSpread);
    QPainter painter(this);
    painter.setBrush(linearGradient);
    painter.drawRect(0,0,width(),height());

    //辐射渐变
    QRadialGradient radialGredient(QPointF(10,20),50,QPointF(20,10));
    radialGredient.setColorAt(0.3,Qt::white);
    radialGredient.setColorAt(0.5,Qt::blue);
    radialGredient.setSpread(QGradient::RepeatSpread);
    QPen pen;
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.setBrush(radialGredient);
    painter.drawEllipse(QPointF(200,200),100,50);

    //锥形渐变
    QConicalGradient conicalGradient(QPointF(200,100),0);
    conicalGradient.setColorAt(0,Qt::black);
    conicalGradient.setColorAt(0.3,Qt::cyan);
    conicalGradient.setColorAt(0.7,Qt::yellow);

    painter.setBrush(conicalGradient);
    painter.drawEllipse(QPointF(200,100),50,50);
}

void Widget::on_pushButton_clicked()
{
    update();
}
