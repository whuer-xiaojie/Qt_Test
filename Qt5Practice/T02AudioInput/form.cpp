#include "form.h"
#include "ui_form.h"
#include <QFile>
#include <QDebug>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);


}

Form::~Form()
{
    delete ui;
}

void Form::on_startRecord_clicked()
{
    QAudioFormat format;
    format.setSampleRate(44100);
    format.setSampleSize(32);
    format.setSampleType(QAudioFormat::Float);
    format.setByteOrder(QAudioFormat::BigEndian);
    format.setChannelCount(2);
    format.setCodec("audio/pcm");

    // 放置录音设备，不支持咱们的格式，让录音设备自己选择一个格式
    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if (!info.isFormatSupported(format)) {
        qWarning() << "Default format not supported, trying to use the nearest.";
        format = info.nearestFormat(format);

        qDebug() << format.sampleRate();
        qDebug() << format.sampleSize();
        qDebug() << format.sampleType();
        qDebug() << format.byteOrder();
        qDebug() << format.channelCount();
        qDebug() << format.codec();
    }

    file = new QFile(filename);
    if(!file->open(QFile::WriteOnly))
    {
        qDebug() << "open error";
        return;
    }

    _input = new QAudioInput(format);
    // 录制的声音，直接写入file中
    _input->start(file);
}

void Form::on_stopRecord_clicked()
{
    _input->stop();
    file->close();
    delete file;
    delete _input;
}

void Form::on_play_clicked()
{
    QAudioFormat format;
    format.setSampleRate(44100);
    format.setSampleSize(32);
    format.setSampleType(QAudioFormat::Float);
    format.setByteOrder(QAudioFormat::BigEndian);
    format.setChannelCount(2);
    format.setCodec("audio/pcm");

    // 放置录音设备，不支持咱们的格式，让录音设备自己选择一个格式
    QAudioDeviceInfo info = QAudioDeviceInfo::defaultOutputDevice();
    if (!info.isFormatSupported(format)) {
        qWarning() << "Default format not supported, trying to use the nearest.";
        format = info.nearestFormat(format);
    }
    _output = new QAudioOutput(format);

    file = new QFile(filename);
    if(!file->open(QFile::ReadOnly))
    {
        qDebug() << "open file error";
        return;
    }

    connect(_output, &QAudioOutput::stateChanged, [&](QAudio::State state){
        if(state == QAudio::StoppedState)
        {
            file->close();
            delete file;
            delete _output;
        }
    });

    _output->start(file);
}
