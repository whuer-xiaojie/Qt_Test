#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

     //QApplication app(argc, argv);
      QPixmap pixmap("testioco.png");
      QSplashScreen splash(pixmap);
      splash.show();
      for(long index=0;index<=800000000;index++);
      /*app.processEvents();
      ...
      QMainWindow window;
      window.show();
      */


    MainWindow w;
    w.show();
    splash.finish(&w);
    //return app.exec();
    return a.exec();
}
