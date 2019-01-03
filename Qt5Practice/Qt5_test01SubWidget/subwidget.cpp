#include "subwidget.h"
//#include"widget.h"
#include<QVBoxLayout>

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)//自定义一个窗口和主窗口相互独立
{
    this->setMaximumSize(360,360);
    this->setMinimumSize(360,360);
    this->setWindowTitle("SubWidget" );
    backButton=new QPushButton(this);//在子窗口中添加Button
    backButton->setText("back");
    exitButton=new QPushButton(this);
    exitButton->setText("exit");

    QWidget *window=new QWidget(this);
    QVBoxLayout *Vlayout=new QVBoxLayout;//定义垂直布局
    Vlayout->addWidget(backButton);//把Button添加到布局中
    Vlayout->addWidget(exitButton);

    window->setLayout(Vlayout);//为布局添加到一个显示窗口
    window->move(200,300);//设置布局在窗口中的位置
    window->show();

    //this->connect(backButton,&QPushButton::clicked,this,&SubWidget::backToMainWidget);
    this->connect(backButton,&QPushButton::clicked,this,&SubWidget::sentSingnalToMainWidget);//为主窗口发backButton被按下的信号
    this->connect(exitButton,SIGNAL(clicked(bool)),this,SLOT(sentExitSignal()));//发出exitButton被按下的信号



}
/*
void SubWidget::backToMainWidget()
{
    this->close();
    Widget *widget=new Widget;
   widget->show();
}
*/
 void SubWidget::sentSingnalToMainWidget()//信号发射槽函数
 {
     emit backToMainWindowSingnal();//信号发射

 }
  void SubWidget::sentExitSignal()
  {
      emit exitSignal();
  }
