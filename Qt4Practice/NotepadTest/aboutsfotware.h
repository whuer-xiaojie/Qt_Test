#ifndef ABOUTSFOTWARE_H
#define ABOUTSFOTWARE_H

#include <QDialog>
#include <QMovie>
//#include <QSound>


namespace Ui {
class aboutSfotware;
}

class aboutSfotware : public QDialog
{
    Q_OBJECT

public:
    explicit aboutSfotware(QWidget *parent = 0);
    ~aboutSfotware();

private:
    Ui::aboutSfotware *ui;
    QMovie *movie;
    //QSound *sound;
private slots:
    void startButton();
    void stopButton();

   // void MusicOn();
   // void MusicOff();
};

#endif // ABOUTSFOTWARE_H
