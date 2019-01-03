#-------------------------------------------------
#
# Project created by QtCreator 2017-04-07T15:31:41
#
#-------------------------------------------------

QT       += core gui
QT       +=network
CONFIG +=C++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpClient
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui
