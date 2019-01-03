#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>
#include<QListWidgetItem>
#include <QListWidget>
#include<QDir>
#include<QMessageBox>


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
    void addToListWidget();
    void removeFormListWidget();
    void removeAllFormListWidget();

    void showDir();

    void singalClicked(QListWidgetItem *);
    void doubleClicked(QListWidgetItem *);
};

#endif // MAINWINDOW_H
