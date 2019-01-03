#-------------------------------------------------
#
# Project created by QtCreator 2017-04-01T08:25:41
#
#-------------------------------------------------
QT      +=network
QT       += core gui
CONFIG +=C++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt5_test08Tcp
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    customerwidget.cpp

HEADERS  += widget.h \
    customerwidget.h

FORMS    += widget.ui \
    customerwidget.ui
