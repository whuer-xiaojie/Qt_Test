TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    ../backImage/image1.jpg \
    ../backImage/image2.jpg \
    ../backImage/image3.jpg \
    ../backImage/image4.jpg \
    ../backImage/image5.jpg
