#include "widget.h"
#include<QDebug>
#include<QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setMaximumSize(360,360);
    this->setMinimumSize(360,360);
    this->setWindowTitle("MainWinget");
    //subWidget=new SubWidget;


    //添加按钮
    closeButton=new QPushButton(this);
    closeButton->setText("close");
    turnButton=new QPushButton(this);
    turnButton->setText("Turnto");
    printfButton=new QPushButton(this);
    printfButton->setText("prinft");

    //按钮布局
    QWidget *Wid=new QWidget(this);
    QHBoxLayout *Hlayout=new QHBoxLayout;
    Hlayout->addWidget(closeButton);
    Hlayout->addWidget(turnButton);
    Hlayout->addWidget(printfButton);
    Wid->setLayout(Hlayout);
    Wid->move(100,300);//设置布局所在位置（走上角为默认位置（0.0））
    Wid->show();

    //切换到子窗口
    this->connect(turnButton,&QPushButton::released,this,&Widget::turnToSubWidget);

    //关闭主窗口
    this->connect(closeButton,&QPushButton::clicked,this,&Widget::close);
    //this->connect(turnButton,SIGNAL(clicked(bool)),this,SLOT(turnToSubWidget()));

    //Lambda表达式运用，打印
    this->connect(printfButton,&QPushButton::clicked,
                  [=]()
    {
        qDebug()<<printfButton->text();
    }//不用再写槽
    );

    //处理子窗口信号
    connect(&subWidget,&SubWidget::backToMainWindowSingnal,this,&Widget::dealSubWidgetSignal);
    connect(&subWidget,SIGNAL(exitSignal()),this,SLOT(dealExitSignal()));

}

Widget::~Widget()
{

}
void Widget::turnToSubWidget()//切换槽
{
    this->hide();
    //subWidget=new SubWidget;
    subWidget.show();

}
void Widget::dealSubWidgetSignal()//返回信号处理槽
{
    this->show();
    subWidget.hide();
}
void Widget::dealExitSignal()//退出信号处理槽
{
    QMessageBox msgBox;
    msgBox.setText("Exit Button");
    msgBox.setInformativeText("Do you sure to close?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();
    switch (ret)
    {
    case QMessageBox::Yes:
        //close
        this->close();
        subWidget.close();
        break;
    case QMessageBox::No:
        // not close
        this->hide();
        subWidget.show();
        break;
    case QMessageBox::Cancel:
        // Cancel was clicked
        break;
    default:
        // should never be reached
        break;
    }
}
