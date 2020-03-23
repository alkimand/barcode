#include "Articles.h"
#include "Groups.h"

#include <QQmlEngine>
#include <QFile>

#include <QDebug>

bool Groups::m_status = false;

static QMap<QString, Articles*> load_from_file(QString file) {
    QFile csv(file);
    csv.open(QIODevice::ReadOnly | QIODevice::Text);

    QString group;
    QMap<QString, Articles*> items;
    Articles* articles;
    QAbstractListModel* test;

    while (!csv.atEnd()) {
        QString line = csv.readLine();

        if (line.at(0) != '\t') {
            if (group.size() > 0)
                items[group] = articles;

            group = line.trimmed();
            articles = new Articles();
        }
        else if (group.size() > 0) {
            QStringList list = line.split('\t');
            articles->append(new Article(list[1].trimmed(),
                                         list[2].trimmed(),
                                         list[3].trimmed()));
        }
    }

    test = articles;

    if (group.size() > 0)
        items[group] = articles;

    for (QString s: items.keys())
        qInfo() << __LINE__ << "key:" << s;

    return items;
}

QObject *Groups::init(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

//    load_from_file(":/shop.csv");

    static Groups* newGroups = new Groups;
    if (!m_status)
    {
        QStringList list = QStringList()
                << "Фрукты"
                << "Овощи"
                << "Конфеты";

        for (QString name : list)
            newGroups->list.append(name);

        newGroups->items = load_from_file(":/shop.csv");

        qInfo() << newGroups->items["Конфеты"]->rowCount();

//        newGroups->list.append("Фрукты");
//        newGroups->list.append("Овощи");
//        newGroups->list.append("Конфеты");


        m_status = true;
    }

    return newGroups;
}
