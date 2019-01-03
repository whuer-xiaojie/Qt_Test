#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimer>
#include"mythread.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void timeout();

private slots:
    void on_pushButton_clicked();
    void dealTimeout();
    void dealisDone();
    void closeThread();


private:
    Ui::Widget *ui;
    QTimer *myTimer;
   myThread *thread;
};

#endif // WIDGET_H
