#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
   ui->label->setStyleSheet("QLabel{color:red;"
                             "border-image:url(:/new/prefix1/image/fc8180442b046bec676f11173a28cccb.jpg);"
                             "}");//设置背景图片和字体颜色
    //ui->label_2->setStyleSheet("QLabel{color:green;"
    //                           "background-color:red;"
     //                          "}");
    ui->pushButton->setStyleSheet("QPushButton{"
                                  "border:4px outset green;"
                                  "border-image:url(:/new/prefix1/image/2985590541be794fe9100a138c32d55e.jpg);"
                                  "}"//默认时的背景图片
                                  "QPushButton:hover{"
                                  "border-image:url(:/new/prefix1/image/fc8180442b046bec676f11173a28cccb.jpg);"
                                  "}"
                                  "QPushButton:pressed{"
                                  "border-image:url(:/new/prefix1/image/aa5805a64691491a2edeefd750e3e00a.jpg);"
                                  "}"//鼠标被按下时的背景图片
                                  );
}

Widget::~Widget()
{
    delete ui;
}
