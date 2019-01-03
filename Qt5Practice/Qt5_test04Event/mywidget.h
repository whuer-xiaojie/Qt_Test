#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QEvent>
#include<QTextEdit>

class myWidget : public QWidget
{
    Q_OBJECT
public:
    explicit myWidget(QWidget *parent = 0); 
    //QTextEdit *text;
protected:
    void enterEvent(QEvent *event);//光标进入事件
    void leaveEvent(QEvent *event);//光标离开事件

signals:


public slots:
};

#endif // MYWIDGET_H
