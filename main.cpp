#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <string>
#include <iostream>
#include <QString>

int main(int argc, char *argv[])
{

    std::string str = "nam123";

    QString a = QString::fromUtf8(str.c_str());
    qDebug() << a;


    //std::cout << tr;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
