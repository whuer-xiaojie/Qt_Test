#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),


    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("No Title Notepad");//设置主窗口的标题

    //文件栏
    QObject::connect(ui->NewAction,SIGNAL(triggered(bool)),this,SLOT (NewFile()));//新建按钮关联到新建槽
    QObject::connect(ui->OpenAction,SIGNAL(triggered(bool)),this,SLOT(OpenFile()));//打开按钮关联到打开槽
    QObject::connect(ui->SaveAction,SIGNAL(triggered(bool)),this,SLOT(SaveToFile()));//保存按钮关联到保存槽（存在判断）

    //编辑栏
    QObject::connect(ui->CutAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(cut()));//剪贴
    QObject::connect(ui->UndoAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(undo()));//撤销
    QObject::connect(ui->CopyAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(copy()));//拷贝
    QObject::connect(ui->PasteAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(paste()));//粘贴
    QObject::connect(ui->SelectAllAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(selectAll()));//全选

    //格式
    QObject::connect(ui->ColorAction,SIGNAL(triggered(bool)),this,SLOT(ColorSlot()));
    QObject::connect(ui->TypeFontAction,SIGNAL(triggered(bool)),this,SLOT(TypeFont()));
    QObject::connect(ui->DataTimeAction,SIGNAL(triggered(bool)),this,SLOT(DateTime()));

    QObject::connect(ui->aboutQtAction,SIGNAL(triggered(bool)),qApp,SLOT(aboutQt()));
    QObject::connect(ui->aboutWebAction,SIGNAL(triggered(bool)),this,SLOT(aboutWeb()));
   QObject::connect(ui->aboutSoftAction,SIGNAL(triggered(bool)),this,SLOT(aboutsoft()));


}
void MainWindow::closeEvent(QCloseEvent *cevent)
{
    //cevent->ignore();
    if(ui->textEdit->document()->isModified())
    {

        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");//提示文件已经被修改
        msgBox.setInformativeText("Do you want to save your changes?");//需要保持？
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret) {
            case QMessageBox::Save:
                // Save was clicked
            this->SaveToFile();
                break;
            case QMessageBox::Discard:
                // Don't Save was clicked
            cevent->accept();
                break;
            case QMessageBox::Cancel:
                // Cancel was clicked
            cevent->ignore();
                break;
            default:
                // should never be reached
                break;
          }
    }
    else
    {
        cevent->accept();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


//文件
void MainWindow:: NewFile()//新建
{
    if(ui->textEdit->document()->isModified())
    {
        //QMessageBox::information(this,"Save The Text","Are You Sure To Save?");
       // QObject::connect(ui->NewAction,SIGNAL(triggered(bool)),this,SLOT(SaveFile()));
        QMessageBox::information(this,"Save The Text","Are You Sure To Save?");
        this->SaveToFile();
        qDebug()<<"The file is changed";
    }
    else
   {
       // QMessageBox::information(this,"Save The Text","Are You Sure To Save?");
        qDebug()<<"The file not change";
        ui->textEdit->clear();
        this->setWindowTitle(" Not Changed Text");
    }
}
void MainWindow::OpenFile()//打开一个现有文件
{
    QString fileName=QFileDialog::getOpenFileName(this,"Open File",QDir::currentPath());//切换到当前路径下打开一个文件并返回文件名称QString类型
    qDebug()<<"the file name is:"<<fileName;//在输出窗口打印文件名称
    if(fileName.isEmpty())
    {
        //QMessageBox::information(this,"Error Message","Please Select a Text File");
        QMessageBox::warning(this,"Erroe Message","Please Select a Text File");
        return;
    }
    else
    {
        QFile *file=new QFile;
        this->saveFileName=fileName;//为了修改当前文件并保存设置参数
        file->setFileName(fileName);//设置文件名称
        bool ok=file->open(QIODevice::ReadOnly);//以只读模式打开文档
        if(ok)
        {
            //文件与文本流相关联
            QTextStream in(file);
           ui->textEdit->setText( in.readAll());//读完文件中所有的内容
           file->close();
           delete file;
        }
        else
        {
            //QMessageBox::information(this,"Error Message","File can't Open"+file->errorString());
            QMessageBox::warning(this,"Erroe Message","Please Select a Text File"+file->errorString());
            return;
        }

    }
}
void MainWindow::SaveNewFile()//保存新文件
{
    this->saveFileName=QFileDialog::getSaveFileName(this,"Save Text File",QDir::currentPath());
    if(saveFileName.isEmpty())
    {
        QMessageBox::information(this,"Error Message","Please Input The Name Of The File You'll Save");

        return;
    }
    else
    {
        QFile *file=new QFile;
        file->setFileName(saveFileName);
        bool ok=file->open(QIODevice::WriteOnly);
        if(ok)
        {
           QTextStream out(file);
           out<<ui->textEdit->toPlainText();//输出textEdit中的纯文本文档
           file->close();
           delete file;

        }
        else
        {
            QMessageBox::warning(this,"Error Message","Can't Save");
            return;

        }
    }
}
void MainWindow::SaveToFile()//保存打开的已有文件
{
    if(saveFileName.isEmpty())
    {
        this->SaveNewFile();
    }
    else
    {
        QFile *file=new QFile;
        file->setFileName(saveFileName);
        bool ok=file->open(QIODevice::WriteOnly);
        if(ok)
        {
           QTextStream out(file);
           out<<ui->textEdit->toPlainText();//输出textEdit中的纯文本文档
           file->close();
           delete file;

        }
        else
        {
            QMessageBox::warning(this,"Error Message","Can't Save");
            return;

        }
    }
}


//格式
  void MainWindow:: ColorSlot()//设置字体颜色
  {
      /*
      const QColorDialog::ColorDialogOptions options = QFlag(colorDialogOptionsWidget->value());
      const QColor color = QColorDialog::getColor(Qt::green, this, "Select Color", options);

      if (color.isValid()) {
          colorLabel->setText(color.name());
          colorLabel->setPalette(QPalette(color));
          colorLabel->setAutoFillBackground(true);
      }
  */
      QColor color=QColorDialog::getColor(Qt::red,this);
      if(color.isValid())
      {
          ui->textEdit->setTextColor(color);
      }
      else
      {
          QMessageBox::warning(this,"Error Message","Not Valid Color");
      }


  }
   void MainWindow::TypeFont()//设置字体
   {
       /*
     bool ok;
  QFont font = QFontDialog::getFont(
                  &ok, QFont("Helvetica [Cronyx]", 10), this);
  if (ok) {
      // the user clicked OK and font is set to the font the user selected
  } else {
      // the user canceled the dialog; font is set to the initial
      // value, in this case Helvetica [Cronyx], 10
  }
        */
       bool ok;
       QFont font=QFontDialog::getFont(&ok,this);
       if(ok)
       {
           ui->textEdit->setFont(font);
       }
       else
       {
           QMessageBox::warning(this,"Error Message","Not Find Font");
           return;
       }
   }
   void  MainWindow::DateTime()
   {
       QDateTime current=QDateTime::currentDateTime();
       QString time=current.toString("   dd /MM/ yyyy  hh:mm:ss.zzz");
       ui->textEdit->append(time);

   }
void MainWindow::aboutWeb()
{
    QDesktopServices::openUrl(QUrl("http://www.baidu.com"));
}
void MainWindow::aboutsoft()
{
    aboutSfotware *about=new aboutSfotware;
    about->show();//显示对话框非莫泰
}
