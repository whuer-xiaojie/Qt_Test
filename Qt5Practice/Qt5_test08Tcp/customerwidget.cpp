#include "customerwidget.h"
#include "ui_customerwidget.h"
#include<QHostAddress>
#include<QMessageBox>

customerWidget::customerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customerWidget)
{
    ui->setupUi(this);
    tcpSocket=NULL;
    setWindowTitle(" 客户端 ");
    tcpSocket=new QTcpSocket(this);
    connect(tcpSocket,&QTcpSocket::connected,//与服务器连接成功
                    [=]()
                   {
                           ui->recriveTextEdit->setText("与服务器连接成功");
                   }
            );
    connect(tcpSocket,&QTcpSocket::readyRead,//接收对方给我发送的信息
                      [=]()
                     {
                              ui->recriveTextEdit->append(tcpSocket->readAll());
                      }
            );

}

customerWidget::~customerWidget()
{
    delete ui;
}

void customerWidget::on_pushButton_clicked()//建立连接
{
    //获取服务器IP和端口号
    QString IP=ui->IPLineEdit->text();
    qint16 port=ui->portLineEdit->text().toInt();

    //连接到服务器
    tcpSocket->connectToHost(QHostAddress(IP),port);

}

void customerWidget::on_sentButton_clicked()
{
    //获取发送内容
    QString str=ui->sentTextEdit->toPlainText();

    //发送
    tcpSocket->write(str.toUtf8().data());
}

void customerWidget::on_closeButton_clicked()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}
