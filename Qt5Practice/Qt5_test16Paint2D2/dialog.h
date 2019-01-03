#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QMouseEvent>
#include<QWheelEvent>
#include<QPainter>
//#include<QPaintEvent>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
protected slots:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void zoomIn();
private:
    Ui::Dialog *ui;
    QPoint startPoint;
    QPoint endPoint;
    QPixmap pix;
    int scale=1;
};

#endif // DIALOG_H
