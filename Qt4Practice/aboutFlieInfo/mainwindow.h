#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileInfo>
#include<QDateTime>
#include<QFileDialog>
#include<QString>
#include <QDir>
#include<QMessageBox>
#include<QDateTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void getFileInfo();
};

#endif // MAINWINDOW_H
