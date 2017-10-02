#include <QtCore/QUrl>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>

#include <QtQml/qqml.h>
#include <QtQml/QQmlEngine>

#include <QtQuickControls2/QQuickStyle>

#include "nightmodeextension.h"

int main(int argc, char *argv[])
{
    QQuickStyle::setStyle("Material");
    QGuiApplication app(argc, argv);
    qmlRegisterType<NightModeExtensionQuickExtension>("com.theqtcompany.nightmodeextension", 1, 0, "NightModeExtension");
    QQmlApplicationEngine appEngine(QUrl("qrc:/main.qml"));

    return app.exec();
}
