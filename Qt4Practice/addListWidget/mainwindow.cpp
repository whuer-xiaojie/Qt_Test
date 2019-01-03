#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QFileDialog>
#include<QStringList>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->connect(ui->addButton,SIGNAL(clicked(bool)),this,SLOT(addToListWidget()));//添加链接
    this->connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(addToListWidget()));//回车链接
    this->connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(removeFormListWidget()));//删除

    this->connect(ui->removeAllButton,SIGNAL(clicked(bool)),this,SLOT(removeAllFormListWidget()));//全部删除
    this->connect(ui->shoeDirButton,SIGNAL(clicked(bool)),this,SLOT(showDir()));//显示目录

    this->connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(singalClicked(QListWidgetItem*)));//单击item
    this->connect(ui->listWidget,SIGNAL(doubleClicked(QListWidgetItem*)),this,SLOT(doubleClicked(QListWidgetItem*)));//双击item

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addToListWidget()
{
    QString addName=ui->lineEdit->text();
    QListWidgetItem *item=new QListWidgetItem;
    item->setText(addName);
    ui->listWidget->addItem(item);
    ui->lineEdit->clear();
}

void MainWindow::removeFormListWidget()
{
   QListWidgetItem *item=ui->listWidget->takeItem(ui->listWidget->currentRow());
  delete item;

}
void  MainWindow::removeAllFormListWidget()
{
     //int counter=ui->listWidget->count();
     //qDebug()<<"counter="<<counter;
     //QListWidgetItem *item;
    /* for(int i=0;i<ui->listWidget->count();)
     {
         int counter=ui->listWidget->count();
          qDebug()<<"counter="<<counter;
         delete ui->listWidget->takeItem(i);
         i+=1;
         //delete item;
     }
     */
     int count=0;
     while(1)
    {
          QListWidgetItem *item=ui->listWidget->takeItem(count);
          if(item==NULL)
          {
              break;
          }
          else
          {
              delete item;
          }
     }
}
void  MainWindow::showDir()
{
   // QDir dir=QDir::currentPath();
    //QDir *dir;
    //dir->addSearchPath("chose Dir",this);
    QStringList fileName=QDir (QDir::currentPath()).entryList();//获取当前路径下所有文件
     //QStringList fileName=dir->entryList();
    if(fileName.size()<=2)
    {
        QMessageBox::information(this,"Error Message","No file in the Dir");
        return;

    }
    else
    {
        for(int index=0;index<fileName.size();index++)
        {
            QListWidgetItem *item=new QListWidgetItem;
            if(fileName.at(index)=="."||fileName.at(index)=="..")
            {
                continue;
            }
            item->setText(fileName.at(index));
            ui->listWidget->addItem(item);


        }
    }
}
void MainWindow::singalClicked(QListWidgetItem *item)
{
    QMessageBox::information(this,"singalClicked item","Clicked item is"+item->text());
}

void MainWindow::doubleClicked(QListWidgetItem *item)
{
    QMessageBox::information(this,"doubleClicked item","doubleClicked item is"+item->text());
}
