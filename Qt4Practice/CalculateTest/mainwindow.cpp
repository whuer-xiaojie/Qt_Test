#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMaximumSize(350,180);
    this->setMinimumSize(350,180);
    QObject::connect(ui->CalpushButton,SIGNAL(clicked(bool)),this,SLOT(CalculateSlot()));//把计算按钮关联到计算函数槽
    QObject::connect(ui->SecondlineEdit,SIGNAL(returnPressed()),this,SLOT(CalculateSlot()));//把第二个LineEdit输入回车关联到计算函数槽
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::CalculateSlot()
{
    float first=ui->FirstlineEdit->text().toFloat();//读取第一个输入的数
    float second=ui->SecondlineEdit->text().toFloat();//读取第二个数
    float result;
    switch(ui->comboBox->currentIndex())//选择运算方式
    {
    case 0:result=first+second;break;
    case 1:result=first-second;break;
    case 2:result=first*second;break;
    case 3:
        if(second==0)
        {
         //MessageBox::information(this,"error!!!","second can't be 0");//调用QMessageBox的静态成员函数宣示出一个错误提示对话框
          QMessageBox::warning(this,"error!!!!!","second can't be 0");
            break;
        }
        result=first/second;break;





    }

    ui->ResultlineEdit->setText(QString::number(result));//输出计算结果（用QString类型输出）

}
