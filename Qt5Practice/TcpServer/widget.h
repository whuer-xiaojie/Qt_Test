#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>
#include<QFile>
#include<QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public:
    //发送数据函数
   void sentData();

private slots:
    void on_choseButton_clicked();

    void on_sentButton_clicked();

    void recevieFun();

private:
    Ui::Widget *ui;
    //监听套套接器和通信套接器
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    //文件信息
    QFile *file;
    QString fileName;
    qint64 fileSize;
    //已经发送文件大小
    qint64 sentSize;
    //启动数据发送定时器
    QTimer timer;

    qint64 recevieSize;
    bool recevieFlag;
};

#endif // WIDGET_H

