#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPixmap>
#include<QTimer>
#include<QDesktopWidget>
#include<QMessageBox>
#include<QDir>
#include<QContextMenuEvent>
#include <QMenu>
#include<QAction>
#include<QCloseEvent>


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
    void contextMenuEvent(QContextMenuEvent *event);
    void closeEvent(QCloseEvent *event);
private slots:
    void on_createButton_clicked();
    void cutScreen();
    void savePixmap();
    void exitSlot();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QPixmap pixmap;
};

#endif // MAINWINDOW_H
