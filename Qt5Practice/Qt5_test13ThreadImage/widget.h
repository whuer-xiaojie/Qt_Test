#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"mythread.h"
#include<QThread>
#include<QPaintEvent>
#include<QImage>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    myThread *thread;
    QThread *sonThread;
    QImage image;
signals:
    void startThread();
protected slots:
    void dealThreadSignal(QImage image);
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();
    void on_quitButton_clicked();
};

#endif // WIDGET_H
