#include "widget.h"
#include "ui_widget.h"
#include<QMessageBox>
#include <QFileDialog>
#include<QFileInfo>
#include<QTimer>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //初始化监听套接字
    tcpServer=new QTcpServer(this);
    //建立监听
    tcpServer->listen(QHostAddress::Any,6666);
    setWindowTitle("服务器：6666");
    ui->progressBar->setValue(0);

    //两个按钮变灰色不能按下
    ui->choseButton->setEnabled(false);
    ui->sentButton->setEnabled(false);

    //初始化接收标志
    recevieFlag=true;

    //连接客户端
    connect(tcpServer,&QTcpServer::newConnection,
                  [=]()
                  {
                           //获取建立好连接对象的通信套接字
                           tcpSocket=tcpServer->nextPendingConnection();

                           //通信套接字IP和端口
                           QString IP=tcpSocket->peerAddress().toString();
                           qint16 port=tcpSocket->peerPort();
                           //设置格式
                           QString str=QString("与[%1:%2]成功连接").arg(IP).arg(port);
                           //提示对话框

                           QMessageBox::information(this,"information",str);
                           //成功建立连接以后才能按按钮
                           ui->textEdit->append(str);
                           ui->choseButton->setEnabled(true);
                         //  ui->sentButton->setEnabled(true);
                           connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recevieFun()));

                  }

            );
    connect(&timer,&QTimer::timeout,

                    [=]()
                   {
                      timer.stop();
                      qDebug()<<"启动计时器:";
                      sentData();
                    }
            );


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_choseButton_clicked()
{
    QString fileName1=QFileDialog::getOpenFileName(this,"chose file",QDir::currentPath());//获取文件名称（包括文件地址）
    //没有选择文件
    if(fileName1.isEmpty())
    {
        QMessageBox::information(this,"Error Infor","No File Chosed");
    }
    //选择了文件
    else
   {
        file=new QFile;
        file->setFileName(fileName1);

        //获取文件信息
        QFileInfo inf(fileName1);
        fileName=inf.fileName();
        qDebug()<<"文件名:"<<fileName;
        fileSize=inf.size();
        qDebug()<<"文件大小:"<<fileSize;
       bool ok= file->open(QIODevice::ReadOnly);
       //文件打开成功
       if(ok)
       {
               qDebug()<<"文件打开成功";
               //ui->progressBar->setRange(0,fileSize);
               ui->textEdit->append("需要发送的文件:       "+fileName1);

               // QTextStream in(file);
               //ui->textEdit->append(in.readAll());

               //文件成功选择并读取才可以选择发送按钮
               ui->choseButton->setEnabled(false);
               ui->sentButton->setEnabled(true);
       }
       //文件打开失败
       else
      {
           QMessageBox::information(this,"error Message","can't open the File!!!");
           file->close();
       }


    }
}

void Widget::on_sentButton_clicked()
{
    //发送文件头部信息
    QString str=QString("name#%1#size#%2#").arg(fileName).arg(fileSize);
    qDebug()<<"文件头部1:"<<str;
   qint64 len=0;
    len= tcpSocket->write(str.toUtf8());
   //头部信息发送成功
   if(len>0)
   {
       sentSize=0;
       //qDebug()<<"文件头部发送成功:";
       // sentData();
       timer.start(20);//延迟20毫秒
       //发送数据

   }
   //头部发送失败
   else
  {
       QMessageBox::information(this,"Error information","the file head send fale");
       file->close();
       ui->choseButton->setEnabled(true);
       ui->sentButton->setEnabled(false);
   }

}

void Widget::sentData()
{
   //提示文件发送信息
    ui->textEdit->append("文件发送中...........");
    while(1)
    {
        char buff[1024*4]={0};
        //读取的长度
        qint64 lenth=0;
        lenth=file->read(buff,sizeof(buff));
        //数据没有发送完
        if(lenth>0)
        {
            //发送的长度
            lenth=tcpSocket->write(buff,lenth);
            //发送的总长度
           sentSize+=lenth;

        }
        else
        {
            break;
        }

    }
    if(sentSize==fileSize)
    {
        //qDebug()<<"数据发送完了160";
        file->close();
        ui->sentButton->setEnabled(false);
        ui->choseButton->setEnabled(true);
    }
   else
    {
        QMessageBox::information(this,"error!!!","File not send all");
        file->close();
        return;
    }

}
void Widget::recevieFun()
{
     QByteArray Rec=tcpSocket->readAll();
     //接收到的信息
     QString S=Rec;
     //如果是对方接收完成信息就说明发送完成，并返回
     if(S=="finish")
     {
         ui->textEdit->append("文件发送完!!!!!");
         return;
     }
     //对方给我发送文件
    if(recevieFlag)
    {
        //接收头部信息并初始化
        fileName=QString(Rec).section("#",1,1);
        fileSize=QString(Rec).section("#",3,3).toInt();
        ui->progressBar->setRange(0,fileSize/1024);
        file=new QFile;
        file->setFileName("../"+fileName);
        bool ok=file->open(QIODevice::WriteOnly);
        if(ok)
        {
            qDebug()<<"服务器接收文件打开成功:";
        }
        else
        {
            QMessageBox::information(this,"error!!!","接收文件打开失败!!!");
        }
        recevieFlag=false;
        recevieSize=0;
    }

    else
    {
        //接收文件内容
       qint64 writeLen= file->write(Rec);
       recevieSize+=writeLen;
       ui->progressBar->setValue(recevieSize/1024);
       if(recevieSize==fileSize)
       {
           tcpSocket->write("finish");
           QMessageBox::information(this,"finish","文件接收完成:");
       }

    }

}
