#ifndef MYITEM_H
#define MYITEM_H
#include<QtGui>
#include<QGraphicsItem>I
#include<QMouseEvent>
#include<QGraphicsSceneMouseEvent>
class MyItem : public QGraphicsItem
{
    //Q_OBJECT
public:
    MyItem();
public:
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    QColor color;

signals:

public slots:
};
class RectItem : public QGraphicsItem

{

public:

   RectItem();

   QRectF boundingRect() const;

   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

protected:

    void dragEnterEvent(QGraphicsSceneDragDropEvent *event); //拖动进入事件

    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event); //拖动离开事件

    void dropEvent(QGraphicsSceneDragDropEvent *event);  //放入事件

private:

    QColor color;

    bool dragOver;  //标志是否有拖动进入

};

#endif // MYITEM_H
