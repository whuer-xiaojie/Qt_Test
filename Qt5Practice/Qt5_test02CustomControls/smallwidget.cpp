#include "smallwidget.h"
#include<QSlider>
#include<QSpinBox>
#include<QHBoxLayout>

SmallWidget::SmallWidget(QWidget *parent) : QWidget(parent)//自定义子控件（把主窗口中的一个Widget提升为该控件）
{
    QSpinBox *spinBox=new QSpinBox(this);
    QSlider *slider=new QSlider(Qt::Horizontal,this);
    QHBoxLayout *Hlayout=new QHBoxLayout(this);
    Hlayout->addWidget(spinBox);
    Hlayout->addWidget(slider);//只需要添加。不需要定义显示窗口
    setStyleSheet("SmallWidget{"
                  "background-color:red;"
                  "}");
    // connect(spinBox,static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),slider,&QSlider::setValue);
    connect(spinBox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    //connect(slider,SIGNAL(valueChanged(int)),spinBox,SLOT(setValue(int)));
    connect(slider,&QSlider::valueChanged,spinBox,&QSpinBox::setValue);


}
