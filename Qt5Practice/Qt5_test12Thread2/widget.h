#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"mythread.h"
#include<QThread>
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

    myThread  *thread;
    QThread *sonThread;

private slots:
    void on_startButton_clicked();
    void dealMySignal();
    void on_stopButton_clicked();

signals:
    void startThread();


};

#endif // WIDGET_H
