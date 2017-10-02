QT += core gui qml waylandcompositor quickcontrols2

CONFIG += wayland-scanner
CONFIG += c++11
SOURCES += \
    main.cpp \
    nightmodeextension.cpp

OTHER_FILES = \
    main.qml

WAYLANDSERVERSOURCES += \
            ../protocol/nightmode.xml

RESOURCES += compositor.qrc

TARGET = nightmode-compositor

HEADERS += \
    nightmodeextension.h
