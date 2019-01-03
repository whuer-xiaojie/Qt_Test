#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QButtonGroup>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QButtonGroup m_Groupbutton;

public slots:
    void getTwistedPairType(QString S);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
