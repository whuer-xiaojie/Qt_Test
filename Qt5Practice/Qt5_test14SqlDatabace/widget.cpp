#include "widget.h"
#include "ui_widget.h"
#include<QSqlDatabase>
#include<QDebug>
#include<QMessageBox>
#include<QSqlError >
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<QSqlDatabase::drivers();
    //添加数据库
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");

    //连接数据库
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("info");
    if(!db.open() )
    {
        QMessageBox::information(this,"error",db.lastError().text());
        return;
    }

}

Widget::~Widget()
{
    delete ui;
}
