#ifndef CUSTOMERWIDGET_H
#define CUSTOMERWIDGET_H

#include <QWidget>
#include<QTcpSocket>

namespace Ui {
class customerWidget;
}

class customerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit customerWidget(QWidget *parent = 0);
    ~customerWidget();

private slots:
    void on_pushButton_clicked();

    void on_sentButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::customerWidget *ui;
    QTcpSocket *tcpSocket;
};

#endif // CUSTOMERWIDGET_H
