#include "widget.h"
#include <QApplication>
#include"clientwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    clientWidget w2;
   // w2.show();

    return a.exec();
}
