#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->openButton,SIGNAL(clicked(bool)),this,SLOT(getFileInfo()));
    QObject::connect(ui->stopButton,SIGNAL(clicked(bool)),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow:: getFileInfo()
{
    QString fileName=QFileDialog::getOpenFileName(this,"Open File",QDir::currentPath());
    if(fileName.isEmpty())
    {
         QMessageBox::information(this,"No file ","Please select a file");
         return;
    }
    QFileInfo info(fileName);
    ui->sizelineEdit->setText(QString::number(info.size()));
   ui->creatTimelineEdit->setText( info.created().toString("yyyy-MM-dd hh:mm:ss.zzz"));
   ui->lastReadTimelineEdit->setText(info.lastRead().toString("yyyy-MM-dd hh:mm:ss.zzz"));
   if(info.isDir())
   {
       ui->isDirlineEdit->setText("yes");

   }
   else
   {
       ui->isDirlineEdit->setText("no");
   }

}
