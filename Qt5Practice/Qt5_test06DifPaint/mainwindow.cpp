#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QPainter>
#include<QPicture>
#include<QImage>
#include<QDebug>
#include<QPaintEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QPixmap 绘图
    QPixmap pixmap(300,400);//定义一个大小为300*400的pixmap画图设备
    pixmap.fill(Qt::white);//背景填充为白色
    QPainter P(&pixmap);
    P.drawPixmap(0,0,width(),height(),QPixmap("../backImage/home"));
    //P.drawPixmap(0,0,200,300,QPixmap("../backImage/home"));
    pixmap.save("../Pixmap.png");

    //QImage绘图
    QImage image(400,300,QImage::Format_ARGB32);
    QPainter P1(&image);
    P1.drawImage(0,0,QImage("../backImage/image2"));
    for(int i=50;i<100;i++)//对绘出来的图进行修改
    {
        for(int j =0;j<50;j++)
        {
            image.setPixel(QPoint(i,j),qRgb(0,125,165));
        }
        image.save("../image.png");
    }

    //QPicture绘图
    QPicture picture;
    QPainter P3;
    P3.begin(&picture);
    P3.drawPixmap(0,0,200,200,QPixmap("../backImage/image3.jpg"));
    P3.end();
    qDebug()<<"11111111";
    picture.save("../picture.png");//保存下来的图片为二进制格式
}

MainWindow::~MainWindow()
{
    delete ui;
}
   void MainWindow::paintEvent(QPaintEvent *event)//打开保存下来的图片(QPicture)
   {
       //主窗口绘制Picture类型绘制的图
       QPicture pic;
       pic.load("../picture.png");
       QPainter P1(this);
       P1.drawPicture(0,0,pic);

       //QPixmap类型转换为QImage并在主窗口显示出来
       //QPixmap tempImage1;
       QImage tempImagel;
       tempImagel.load("../Pixmap.png");
       QPixmap tempPixmap1=QPixmap::fromImage(tempImagel);
       QPainter PtempPixmap(this);
       PtempPixmap.drawPixmap(0,240,200,200,tempPixmap1);

   }
