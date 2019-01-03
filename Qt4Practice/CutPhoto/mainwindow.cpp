#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include<QDesktopServices>
#include<QCursor>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->connect(ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(savePixmap()));
    this->connect(ui->exitButton,SIGNAL(clicked(bool)),this,SLOT(exitSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_createButton_clicked()
{
    if(ui->checkBox->isChecked())
    {
        this->hide();
        this->timer=new QTimer;
        this->connect(this->timer,SIGNAL(timeout()),this,SLOT(cutScreen()));
        this->timer->start(ui->spinBox->value()*1000);


    }
    else
    {
        qApp->beep();
    }
}
  void MainWindow::cutScreen()
  {
      this->pixmap=QPixmap::grabWindow(QApplication::desktop()->winId());//获取测程序运行界面的截屏，默认为全屏。
      ui->spaceLabel->setPixmap(this->pixmap.scaled(ui->spaceLabel->size()));//把截取的图片按比例进行缩放，然后添加到spaceLabel上。
      this->show();
      this->timer->stop();
  }
    void MainWindow::savePixmap()//保存图片
    {
        QString fileName=QFileDialog::getSaveFileName(this,"save",QStandardPaths::writableLocation(QStandardPaths::PicturesLocation));//设置图片的名字，并且是转到用户目录下的我的图片路径下
        if(fileName.isEmpty())//没有设置图片的名称
        {
            QMessageBox::information(this,"error message","please select a a Dir");
            return;
        }
        this->pixmap.save(fileName);//保存图片，图片格式为.PNG
        //this->pixmap=NULL;
    }

void MainWindow::exitSlot()//退出操作
     {
         if(this->pixmap.isNull())
         {
             this->close();
             return;
         }
         //QMessageBox::information(this)
           QMessageBox msgBox;
           msgBox.setText("The picture has been cuted.");
           msgBox.setInformativeText("Do you want to save your picture?");
           msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
           msgBox.setDefaultButton(QMessageBox::Save);
           int ret = msgBox.exec();

           switch (ret) {
             case QMessageBox::Save:
                 // Save was clicked
               this->savePixmap();
                 break;
             case QMessageBox::Discard:
                this->close();
                 break;
             case QMessageBox::Cancel:
                 // Cancel was clicked
                 break;
             default:
                 // should never be reached
                 break;
           }
     }

 void  MainWindow::contextMenuEvent(QContextMenuEvent *event)//添加右键后的菜单
 {
     QMenu *menu=new QMenu(this);
     QAction *action=new QAction(this);
     QAction *stopAction=new QAction(this);
     stopAction->setText("close ");//设置菜单名称
     action->setText("save as");
     QObject::connect(action,SIGNAL(triggered(bool)),this,SLOT(savePixmap()));//点击菜单进行的操作
     QObject::connect(stopAction,SIGNAL(triggered(bool)),this,SLOT(exitSlot()));
     menu->addAction(action);
     menu->addAction(stopAction);

     menu->exec(QCursor::pos());//启动菜单，并在光标附件显示
 }
 void  MainWindow::closeEvent(QCloseEvent *event)//右键菜单关闭
 {
     if(this->pixmap.isNull())
     {
         event->accept();
     }
     else
     {
         this->exitSlot();//如果有截图了，提示是否保存
     }
 }
