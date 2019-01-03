#include "mywidget.h"
#include<QEvent>
#include<QPushButton>
#include <QDebug>
#include<QTextEdit>


myWidget::myWidget(QWidget *parent) : QWidget(parent)
{
    //QPushButton *newButton=new QPushButton(this);
   //newButton->setText("123");
   // this->connect(newButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    QTextEdit *text=new QTextEdit(this);
    text->setMaximumWidth(200);
    text->setMinimumHeight(100);
    text->setText("Text");

}

void myWidget::enterEvent(QEvent *event)
{
     qDebug()<<"event";
            setStyleSheet("QWidget{"
                      "border-image:url(:/new/prefix1/image/fc8180442b046bec676f11173a28cccb.jpg);"
                     "}");
                //setStyleSheet("background-color: rgb(255, 255, 0);");
               // event->accept();
}

void myWidget::leaveEvent(QEvent *event)
{
                setStyleSheet("QWidget{"
                        "border-image:url(:/new/prefix1/image/aa5805a64691491a2edeefd750e3e00a.jpg);"
                        "}");
}


