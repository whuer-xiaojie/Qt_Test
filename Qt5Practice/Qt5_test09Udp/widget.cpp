#include "widget.h"
#include "ui_widget.h"
#include<QHostAddress>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    udpSocket=new QUdpSocket(this);
    //绑定为任意地址
    udpSocket->bind(4444);
    //udpSocket->bind(QHostAddress::AnyIPv4,4444);
    setWindowTitle("服务器端口：4444");

    //添加主播
   // udpSocket->joinMulticastGroup(QHostAddress("224.0.0.5"));
   // udpSocket->leaveMulticastGroup()


    connect(udpSocket,&QUdpSocket::readyRead,//接收别的端口（或者服务器）发过来的消息
                   [=]()
                 {
                      char buff[1024]={0};//每次读取的内容
                      QHostAddress IP;//对方的IP
                      quint16 port;// 对方的端口
                      qint64 msg=udpSocket->readDatagram(buff,sizeof(buff),&IP,&port);
                      if(msg>0)
                      {
                          //定义输出格式
                          QString str=QString("[%1:%2]%3").arg(IP.toString()).arg(port).arg(buff);
                          ui->textEdit->setText(str);
                      }

                 }
            );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_sentButton_clicked()
{
    //获取对象的IP和端口
    QString IP=ui->IPLineEdit->text();
    qint16 port =ui->portLineEdit->text().toInt();
    //获取发送内容
    QString str=ui->textEdit->toPlainText();
    //发送
    udpSocket->writeDatagram(str.toUtf8(),QHostAddress(IP),port);
}
