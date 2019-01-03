#include <QCoreApplication>
//QApplication 图形界面
#include<QDir>
#include<QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"home path is"<<QDir::homePath();
    qDebug()<<"root path is"<<QDir::rootPath();
    qDebug()<<"temp path is"<<QDir::tempPath();
    qDebug()<<"current path is"<<QDir::currentPath();

    return a.exec();
}
