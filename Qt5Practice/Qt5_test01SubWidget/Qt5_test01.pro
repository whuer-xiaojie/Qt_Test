#-------------------------------------------------
#
# Project created by QtCreator 2017-03-29T10:50:37
#
#-------------------------------------------------
CONFIG+=C++11
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt5_test01
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    subwidget.cpp

HEADERS  += widget.h \
    subwidget.h

RESOURCES += \
    test01image.qrc
