#-------------------------------------------------
#
# Project created by QtCreator 2017-04-07T10:32:32
#
#-------------------------------------------------

QT       += core gui
QT+=network
CONFIG +=C++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpServer
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui
