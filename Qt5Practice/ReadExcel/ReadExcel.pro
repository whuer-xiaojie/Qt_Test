#-------------------------------------------------
#
# Project created by QtCreator 2017-07-28T09:12:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ReadExcel
TEMPLATE = app

QT+=axcontainer

SOURCES += main.cpp\
        mainwindow.cpp \
    excelbase.cpp \
    cinputlinestandard.cpp

HEADERS  += mainwindow.h \
    excelbase.h \
    cinputlinestandard.h

FORMS    += mainwindow.ui \
    cinputlinestandard.ui
