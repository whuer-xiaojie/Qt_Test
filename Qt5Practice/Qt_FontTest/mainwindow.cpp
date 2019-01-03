#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFont>
#include<QFontDatabase>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //引入图形字体
       int fontId = QFontDatabase::addApplicationFont(":/Resource/icon.ttf");  //加入字体，并获取字体ID
       QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);    //获取字体名称
       QFont iconFont = QFont(fontName);
       iconFont.setPixelSize(60);     //设置字体大小
       ui->label->setMinimumSize(60,60);
       ui->label->setFont(iconFont);        //设置Label的字体
       ui->label->setText(QChar(0xf16d));   //设置Label的文体
       ui->label->setStyleSheet("color:red;");

       QPalette blue_pe;
       blue_pe.setColor(QPalette::WindowText,Qt::blue);
       ui->label_2->setMinimumSize(60,60);
       ui->label_2->setFont(iconFont);
       ui->label_2->setText(QChar(0xf186));
       ui->label_2->setPalette(blue_pe);

       ui->label_3->setFont(iconFont);
       ui->label_3->setText(QChar(0xe905));

       ui->label_3->setFont(iconFont);
       ui->label_3->setText(QChar(0xe907));


       QPalette blue_pe4;
       blue_pe4.setColor(QPalette::WindowText,Qt::black);
       ui->pushButton->setMinimumSize(65,65);
       //ui->pushButton->setMinimumSize(60,60);
       ui->pushButton->setFont(iconFont);
       ui->pushButton->setText(QChar(0xf186));
       ui->pushButton->setPalette(blue_pe);


}

MainWindow::~MainWindow()
{
    delete ui;
}
