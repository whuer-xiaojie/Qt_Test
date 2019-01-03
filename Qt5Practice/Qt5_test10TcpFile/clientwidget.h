#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include<QTcpSocket>
#include<QFile>
#include<QTimer>

namespace Ui {
class clientWidget;
}

class clientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit clientWidget(QWidget *parent = 0);
    ~clientWidget();


private slots:
    void on_connectButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void sentFileFun();
    void dealTimer();
    void connectedSlot();

private:
    Ui::clientWidget *ui;
    QTcpSocket *tcpSocket;
    //文件信息
    QFile *file;
    QString fileName;
    qint64 fileSize;
    //已经接收文件大小
    qint64 recevieSize;
    //启动数据发送定时器
    QTimer timer;
    qint64 sentFileSize;
    bool head;


};

#endif // CLIENTWIDGET_H
