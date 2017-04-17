#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Stalker.hh"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    qmlRegisterType<Stalker>("Stalker", 1, 0, "Stalker");


    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/main.qml"));

    return app.exec();
}
