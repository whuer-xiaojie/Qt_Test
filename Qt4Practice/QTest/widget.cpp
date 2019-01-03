#include "widget.h"
#include "ui_widget.h"
//#include <QProcess >

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setMaximumSize(365,103);//设置运行窗口的大小（最大）
    this->setMinimumSize(365,103);//设置运行窗口的大小（最小）相同表示不能改变大小

    QObject::connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(on_pushButton_clicked()));//lineEdit 收到一个回车信号，完成PushButton确定按钮的工作

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    /*
    QObject *parent;
      ...
      QString program = "./path/to/Qt/examples/widgets/analogclock";
      QStringList arguments;
      arguments << "-style" << "fusion";

      QProcess *myProcess = new QProcess(parent);
      myProcess->start(program, arguments);
    */
    QProcess *process=new QProcess ;
    QString StartProgram=ui->lineEdit->text();//取出用户输入的文本
    process->start(StartProgram.trimmed());//去除空格并开始运行输入的命令
    ui->lineEdit->clear();
    this->close();
}
