#include <QtGui>
#include<QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include<QGraphicsView>
#include<QTime>
#include"myitem.h"
int main(int argc,char* argv[ ])

{

  QApplication app(argc,argv);

   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
   QGraphicsScene *scene = new QGraphicsScene;  //场景

   //QGraphicsRectItem *item = new QGraphicsRectItem(100,100,50,50);  //矩形项
 //  MyItem *item=new MyItem;
   //item->setPos(0,0);

   for(int i=0;i<5;i++)
   {
       MyItem *item=new MyItem;
         item->setPos(i*50+20,100);
         scene->addItem(item);
   }
   //scene->addItem(item);  //项添加到场景

   RectItem *rect = new RectItem; //新建矩形
     rect->setPos(100,200);
     scene->addItem(rect);

   QGraphicsView *view = new QGraphicsView; //视图

   view->setScene(scene);  //视图关联场景

   view->show();  //显示视图


  return app.exec();

}
