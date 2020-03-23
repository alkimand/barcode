#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Groups/Groups.h"
#include "Info.h"

#include <QFile>
#include <QDebug>
#include <Groups/Articles.h>

class Items {
    QString name,
            img;
public:
    Items (QString tmpName, QString tmpImg) {
        name = tmpName;
        img = tmpImg;
    }
    QString getName() { return name; }
    QString getImg() { return img; }
};

#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QFile csv(":/shop.csv");
    csv.open(QIODevice::ReadOnly | QIODevice::Text);

    QString group;
    QQmlApplicationEngine engine;
//    qmlRegisterType<Item>("MyData", 1, 0, "Item");
    qmlRegisterSingletonType<Groups>("MyData", 1, 0, "DataGroup", &Groups::init);
    qmlRegisterSingletonType<Info>("MyData", 1, 0, "MyInfo", &Info::init);
    qmlRegisterType<Articles>("MyData", 1, 0, "MyArticles");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
