#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include<QString>
#include<QByteArray>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //system("shutdown -s -t 7200");
    QString commend="shutdown -s -t";
    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(close()));
    int second=ui->lineEdit->text().toInt()*3600;

    commend=commend+" "+QString::number(second);
     char *S=commend.toLatin1().data();
    system(S);

    /*QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(close()));
    timer->start(5*1000);
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}
