#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include<QDebug>
#include<QHBoxLayout>
#include "subwidget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();


private slots:
    void turnToSubWidget();
    void dealSubWidgetSignal();
    void dealExitSignal();
private:
QPushButton *turnButton;
QPushButton *closeButton;
QPushButton *printfButton;
 SubWidget       subWidget;
};

#endif // WIDGET_H
