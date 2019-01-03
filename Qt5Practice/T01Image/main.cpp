
#include <QApplication>

#include <QPixmap> // 效率比较高，针对各个平台进行优化
#include <QImage>  // 比较原始

#include <QDebug>
#include "mywidget.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyWidget w;
    w.show();

    // 800x600
    QImage image("E:\Learn\QT\3.jpg");

  //  qDebug() << image.pixelFormat();
    qDebug() << image.format();
// image = image.scaled()
// image = image.scaledToWidth(image.width()/2);

    for(int i=0; i<400; i++)
        for(int j=0; j<300; j++)
        {
            image.setPixel(i, j, 0x00FF0000);
        }
    image.save("E:\Learn\QT\b.jpg");




    return app.exec();
}
