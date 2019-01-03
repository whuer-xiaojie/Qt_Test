#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = 0);
    //void backToMainWidget();

private:
    QPushButton *backButton;
    QPushButton *exitButton;

signals:
    void backToMainWindowSingnal();
    void exitSignal();

public slots:
    void sentSingnalToMainWidget();
    void sentExitSignal();
};

#endif // SUBWIDGET_H
