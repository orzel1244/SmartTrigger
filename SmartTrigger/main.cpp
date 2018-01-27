#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>
#include <class/Memory/memory.h>
#include <class/Offsets/offsets.h>
#include <class/TriggerBot/triggerbot.h>
#include <QThread>
#include <QTimer>

int main(int argc, char *argv[]) {
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;


    TriggerBot triggerBot;


    QQmlContext* ctx = engine.rootContext();
        ctx->setContextProperty("triggerbot", &triggerBot);



    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
