#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QAudioInput>
#include <QFile>
#include <QAudioOutput>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

    QString filename = "/Users/xueguoliang/Desktop/a.pcm";

    QAudioInput* _input;
    QAudioOutput* _output;
    QFile* file;

private slots:
    void on_startRecord_clicked();

    void on_stopRecord_clicked();

    void on_play_clicked();



private:
    Ui::Form *ui;
};

#endif // FORM_H
