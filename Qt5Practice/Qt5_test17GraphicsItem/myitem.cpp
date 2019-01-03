#include "myitem.h"
#include<QPainter>
#include<QApplication>
#include<QDrag>
#include <QObject>
#include<QWidget>
#include<QVariant>
MyItem::MyItem()
{
       setToolTip("Click and drag me!");  //提示

       setCursor(Qt::PointingHandCursor);   //改变光标形状
       color=QColor(qrand()%255,qrand()%255,qrand()%255);
}
QRectF MyItem::boundingRect()const
{
    qreal penWidth=1;
    return QRectF(0-penWidth/2,0-penWidth/2,50+penWidth,50+penWidth);
}
void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //标明该参数没有被使用
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(color);
    painter->drawRect(0,0,50,50);
}
void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        setCursor(Qt::WhatsThisCursor);
    }

}

void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(QLineF(event->screenPos(),event->buttonDownScreenPos(Qt::LeftButton)).length() < QApplication::startDragDistance())

    {

    //如果鼠标按下的点到现在的点的距离小于程序默认的拖动距离，表明没有拖动，则返回

           return;

    }
   QDrag *drag = new QDrag(event->widget()); //为event所在窗口部件新建拖动对象

   QMimeData *mime = new QMimeData; //新建QMimeData对象，它用来存储拖动的数据

   drag->setMimeData(mime); //关联

   mime->setColorData(color);  //放入颜色数据


   QPixmap pix(50,50);  //新建QPixmap对象，它用来重新绘制圆形，在拖动时显示

   pix.fill(Qt::white);

   QPainter painter(&pix);

   paint(&painter,0,0);

   drag->setPixmap(pix);


   drag->setHotSpot(QPoint(10, 15)); //我们让指针指向圆形的(10,15)点

   drag->exec();  //开始拖动

   setCursor(Qt::OpenHandCursor);   //改变光标形状

}
void MyItem:: mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
       if(event->button()==Qt::LeftButton)
       {
           setCursor(Qt::PointingHandCursor);   //改变光标形状
       }
}



RectItem::RectItem()

{

   setAcceptDrops(true);  //设置接收拖放

   color = QColor(Qt::lightGray);

}


QRectF RectItem::boundingRect() const

{

    return QRectF(0, 0, 50, 50);

}


void RectItem::paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget)

{

    painter->setBrush(dragOver? color.light(130) : color);  //如果其上有拖动，颜色变亮

   painter->drawRect(0,0,50,50);

}

void RectItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)

{

   if(event->mimeData()->hasColor()) //如果拖动的数据中有颜色数据，便接收

    {

       event->setAccepted(true);

       dragOver = true;

       update();

    }

   else event->setAccepted(false);

}


void RectItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)

{

   Q_UNUSED(event);

   dragOver = false;

   update();

}


void RectItem::dropEvent(QGraphicsSceneDragDropEvent*event)

{

   dragOver = false;

if(event->mimeData()->hasColor())

//我们通过类型转换来获得颜色

       //color =<QColor>qVariantValue(event->mimeData()->colorData());

   update();

}



