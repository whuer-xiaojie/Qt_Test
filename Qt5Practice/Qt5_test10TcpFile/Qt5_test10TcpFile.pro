#-------------------------------------------------
#
# Project created by QtCreator 2017-04-01T14:32:05
#
#-------------------------------------------------

QT       += core gui
QT+=network
CONFIG +=C++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt5_test10TcpFile
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    clientwidget.cpp

HEADERS  += widget.h \
    clientwidget.h

FORMS    += widget.ui \
    clientwidget.ui
