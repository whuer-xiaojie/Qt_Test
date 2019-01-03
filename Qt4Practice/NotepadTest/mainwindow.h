#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtDebug>
#include <QFile>
#include<QFileDialog>
#include <QDir>
#include<QFontDialog>
#include<QFont>
#include<QColor>
#include<QColorDialog>
#include<QDateTime>
#include<QUrl>
#include<QDesktopServices>
#include<aboutsfotware.h>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *cevent);
private:
    Ui::MainWindow *ui;
    QString saveFileName;//文件保存方式中间变量

private slots:
    //文件
    void OpenFile();
    void NewFile();
    void SaveNewFile();//保存新建的文档
    void SaveToFile();//保存到打开的已有文档

    //格式
    void ColorSlot();
    void TypeFont();
    void DateTime();

    void aboutWeb();//默认浏览器打开一个网站
    void aboutsoft();//弹出一个窗口

};

#endif // MAINWINDOW_H
