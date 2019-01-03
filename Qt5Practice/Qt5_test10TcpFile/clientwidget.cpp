#include "clientwidget.h"
#include "ui_clientwidget.h"
#include<QHostAddress>
#include<QFileDialog>
#include<QIODevice>
#include<QMessageBox>
#include<QFileInfo>
clientWidget::clientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientWidget)
{
    ui->setupUi(this);
    this->tcpSocket=new QTcpSocket(this);
    ui->progressBar->setValue(0);
    head=true;
    //设置按钮
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    //成功连接
   connect(tcpSocket,SIGNAL(connected()),this,SLOT(connectedSlot()));
   //接收数据
    connect(tcpSocket,&QTcpSocket::readyRead,
                      [=]()
                      {
                          QByteArray buff= tcpSocket->readAll();
                          QString S=buff;
                          if(S=="finish")
                          {
                              ui->textEdit->append("文件发送完!!!!!!");
                              return;
                          }
                           if(head)
                           {
                               head=false;
                               //初始化
                               fileName=QString(buff).section("#",1,1);
                               //qDebug()<<"接收文件名:"<<fileName;
                               fileSize=QString(buff).section("#",3,3).toInt();
                               //qDebug()<<"接收文件大小:"<<fileSize;
                               if(fileName.isEmpty()||fileSize<=0)
                               {
                                   return;
                               }
                               recevieSize=0;
                               ui->progressBar->setRange(0,fileSize);
                               //文件的打开
                               file=new QFile(this);
                               file->setFileName(fileName);//当前路径下
                              bool ok=file->open(QIODevice::WriteOnly);
                               if(ok)
                               {
                                  qDebug()<<"客户端成功打开写入文件";

                               }
                               else
                               {
                                   qDebug()<<"文件无法写入:";
                                   file->close();
                                   return;
                               }
                           }
                           else
                           {
                               //存数据
                                qint64 lenth=file->write(buff);
                                 recevieSize+=lenth;
                                 ui->progressBar->setValue(recevieSize);
                                 if(recevieSize==fileSize)
                                 {
                                      //qDebug()<<"文件接收完成，大小为:"<<recevieSize;
                                     tcpSocket->write("finish");
                                      QMessageBox::information(this,"fanish","文件接收完成！！！！");
                                      ui->progressBar->setValue(0);
                                      file->close();
                                      head=true;
                                      return;
                                 }


                           }
                     }

            );
    connect(&timer,&QTimer::timeout,this,& clientWidget::dealTimer);
}

clientWidget::~clientWidget()
{
    delete ui;
}
void clientWidget::connectedSlot()
{
    ui->pushButton->setEnabled(true);
}

void clientWidget::on_connectButton_clicked()
{
    QString IP=ui->IPLineEdit->text();
    qint16 port=ui->portLineEdit->text().toInt();
    tcpSocket->connectToHost(QHostAddress(IP),port);
}

void clientWidget::on_pushButton_clicked()
{
    //向服务器发送文件打开
    QString filePath=QFileDialog::getOpenFileName(this,"open","../");
    if(filePath.isEmpty())
    {
        QMessageBox::information(this,"error","没有选择文件!!!!!!!!");
        return;
    }
    file=new QFile(this);
    file->setFileName(filePath);

    QFileInfo inf(filePath);
    fileName=inf.fileName();
    fileSize=inf.size();

    bool ok=file->open(QIODevice::ReadOnly);
    if(ok)
    {
        ui->textEdit->setText("发送的文件:     "+filePath);
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
    }
    else
    {
        return;
    }
}

void clientWidget::on_pushButton_2_clicked()
{

//发送文件头部

    QString str=QString("name#%1#size#%2#").arg(fileName).arg(fileSize);
    qint64 lenSent=tcpSocket->write(str.toUtf8());
    if(lenSent>0)
    {
        //头部发送成功开始发送文件内容
        sentFileSize=0;
        timer.start(20);
    }
    else
    {
        return;
        file->close();
    }

}
void clientWidget::sentFileFun()
{
    ui->textEdit->append("文件发送中............");
   do
    {
        char A[1024*4]={0};
       qint64 readLen=0;
       readLen = file->read(A,sizeof(A));
       if(readLen>0)
       {
           readLen=tcpSocket->write(A,readLen);
           sentFileSize+=readLen;
           if(sentFileSize==fileSize)
           {
               //ui->textEdit->append("完成");
               qDebug()<<"客户端文件发送完成:";
               ui->pushButton->setEnabled(true);
               ui->pushButton_2->setEnabled(false);
               file->close();
           }
       }

    }
  while(sentFileSize!=fileSize);
}

void clientWidget::dealTimer()
{
    timer.stop();
    sentFileFun();
}




































