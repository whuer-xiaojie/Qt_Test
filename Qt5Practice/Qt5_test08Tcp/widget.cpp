#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("服务端：5000");
    tcpServer=NULL;
    tcpSocket=NULL;
    //监听套接字
    //指定父对象是为了自动回收空间
    tcpServer=new QTcpServer(this);

    tcpServer->listen(QHostAddress::Any,5000);//主机的所有端口都监听，连接端口为5000；

    connect(tcpServer,&QTcpServer::newConnection,
                    [=]()
                    {
                           //取出建立好连接的套接字
                           tcpSocket=tcpServer->nextPendingConnection();

                           //获取对方的IP端口
                           QString IP=tcpSocket->peerAddress().toString();
                           qint16 port=tcpSocket->peerPort();
                           QString temp =QString("[%1:%2:成功连接").arg(IP).arg(port);
                           ui->receiveTextEdit->setText(temp);

                           //连接建立好以后开始接收
                           connect(tcpSocket,&QTcpSocket::readyRead,
                                             [=]()
                                             {
                                                   ui->receiveTextEdit->append(tcpSocket->readAll());
                                             }
                                   );
                    }
            );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_sentButton_clicked()
{
    if(tcpSocket==NULL)
    {
        return;
    }
    //取出编辑区内容
    QString str=ui->sentTextEdit->toPlainText();
    //给对方发送数据，用通信套接字
    tcpSocket->write(str.toUtf8().data());
}

void Widget::on_closeButton_clicked()
{
    if(tcpSocket==NULL)
    {
        return;
    }
    //主动断开与客户端的连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket=NULL;
}
