#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QPaintEvent>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //去除主窗口的边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    //把主窗口的背景颜色去除
    setAttribute(Qt::WA_TranslucentBackground);

    setGeometry(100,100,300,400);
    setWindowFlags(Qt::WindowStaysOnTopHint | windowFlags());
    //setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
    //               Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint|
    //               windowFlags());


}

Widget::~Widget()
{
    delete ui;
}
//void Widget::activateWindow()
//{
//    Qt::WindowStates winStatus=Qt::WindowNoState;
//    if(windowState()&Qt::WindowMaximized)
//    {
//        winStatus=Qt::WindowMaximized;
//    }
//    setWindowState(Qt::WindowMinimized);
//    setWindowState(Qt::WindowActive|winStatus);
//    setGeometry(curGemRect);
//    activateWindow();
//    raise();
//}
//void Widget::resizeEvent(QResizeEvent *e)
//{
//    //curGemRect=geometry();
//}
//
//void Widget::moveEvent(QMoveEvent *e)
//{
//    //curGemRect=geometry();
//}

void Widget::paintEvent(QPaintEvent *event)//绘制背景图
{
    QPainter  P(this);
    P.drawPixmap(0,0,width(),height(),QPixmap("../backImage/image4"));

}
void Widget::mousePressEvent(QMouseEvent *event)//鼠标右键关闭，左键按下获取坐标差
{
    this->raise();

    if(event->button()==Qt::RightButton)
    {
        this->close();
    }
    else
    {
        p=event->globalPos()-this->frameGeometry().topLeft();//坐标差
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)//按着左键进行移动（相对于屏幕）
{
    if(event->buttons()&Qt::LeftButton)
    {
        move(event->globalPos()-p);
    }
}
