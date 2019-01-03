#include "mywidget.h"
#include <QPainter>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent), _image("E:\Learn\QT\3.jpg")
{
    _image = QImage ("E:\Learn\QT\3.jpg");

    _image.save("E:\Learn\QT\3.jpg");

    // 10x10~500x500 颜色修改下
    for(int row=10; row<500; ++row)
        for(int col=10; col<500; ++col)
        {
            _image.setPixelColor(row, col, QColor(Qt::red));
        }

    _image = _image.convertToFormat(QImage::Format_RGB444);
}

void MyWidget::paintEvent(QPaintEvent *event)
{

    QPainter p(this);

    QImage image = _image.scaled(size(),
                                 Qt::IgnoreAspectRatio,
                                 Qt::SmoothTransformation);
    p.drawImage(0, 0, image);
}
