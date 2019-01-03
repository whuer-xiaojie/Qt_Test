#include "widget.h"
#include <QApplication>
#include"customerwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    customerWidget w2;
    w2.show();

    return a.exec();
}
