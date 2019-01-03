
QT += gui widgets multimedia

linux{
LIBS +=  -pthread -lavdevice -lavfilter -lswscale -lpostproc -lavformat -lavcodec \
-lxcb-xfixes -lxcb-render -lxcb-shape   -lxcb -lXext -lXv -lX11 -lasound \
 -lx264 -lpthread -ldl -lfaac -lz -lswresample -lavutil -lm
}
mac{
INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib -lavdevice -lavfilter -lswscale -lpostproc -lavformat -lavcodec -lavutil -lswresample
}
CONFIG += C++11

SOURCES += \
    main.cpp \
    reader.cpp \
    data.cpp \
    surface.cpp \
    player.cpp

HEADERS += \
    reader.h \
    data.h \
    surface.h \
    player.h

