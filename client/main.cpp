#include <QGuiApplication>
#include <QtQml/QQmlApplicationEngine>

#include <QtQml/qqml.h>
#include <QtQml/QQmlEngine>
#include "nightmodeextension.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<NightModeExtension>("com.theqtcompany.nightmodeextension", 1, 0, "NightModeExtension");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

