TEMPLATE = app
QT += qml quick waylandclient
CONFIG += wayland-scanner

WAYLANDCLIENTSOURCES += ../protocol/nightmode.xml

SOURCES += main.cpp \
    nightmodeextension.cpp

HEADERS += \
    nightmodeextension.h

RESOURCES += qml.qrc
