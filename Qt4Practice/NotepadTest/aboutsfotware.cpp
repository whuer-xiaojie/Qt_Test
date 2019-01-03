#include "aboutsfotware.h"
#include "ui_aboutsfotware.h"

aboutSfotware::aboutSfotware(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutSfotware)
{
    ui->setupUi(this);
    this->movie=new QMovie("testgif.gif");
    ui->GifLabel->setMovie(this->movie);
   // this->movie->start();
    QObject::connect(ui->StartButton,SIGNAL(clicked(bool)),this,SLOT(startButton()));
    this->connect(ui->StopButton,SIGNAL(clicked(bool)),this,SLOT(stopButton()));
}

aboutSfotware::~aboutSfotware()
{
    delete ui;
}
void aboutSfotware::startButton()
{
    this->movie->start();
}
void aboutSfotware::stopButton()
{
    this->movie->stop();
}

/*
void aboutSfotware::MusicOn()//音乐开
{

      mediaObject=Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(音乐文件));

      mediaObject->play();

}
*/

/*
void aboutSfotware::MusicOff()//音乐关

{

      mediaObject->stop();

}
*/

