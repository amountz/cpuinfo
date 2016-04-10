#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include "cpuinfo.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Cpuinfo *cpuinfo = new Cpuinfo;
    engine.rootContext()->setContextProperty("cpuinfo", cpuinfo);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

