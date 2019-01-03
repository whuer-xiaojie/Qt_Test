#include "dialog.h"
#include "ui_dialog.h"
#include<QPushButton>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setMaximumSize(350,400);
    this->setMinimumSize(350,400);
    pix=QPixmap(400,330);
    pix.fill(Qt::white);
    QPushButton *button=new QPushButton(this);
   button->setText("放大");
    button->move(250,340);
    connect(button,SIGNAL(clicked(bool)),this,SLOT(zoomIn()));
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        startPoint=event->pos();
    }
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        endPoint=event->pos();
        update();
    }
}
void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        endPoint=event->pos();
        update();
    }
}
void Dialog:: paintEvent(QPaintEvent *event)
{
    QPainter P(&pix);
    P.drawLine(startPoint/scale,endPoint/scale);
    startPoint=endPoint;
    QPainter painter(this);
    painter.scale(scale,scale);
    painter.drawPixmap(0,0,pix);
}
void Dialog::zoomIn()
{
    scale*=2;
    update();
}
