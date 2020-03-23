#include "Articles.h"
#include "Groups.h"

#include <QQmlEngine>


Groups::Groups(QObject *parent)
    : QAbstractListModel(parent)
{
//    list.append("Фрукты");
//    list.append("Овощи");
//    list.append("Конфеты");

//    candy.append(new Element("O'Rera Truffle",":/imgs/O'Rera_Truffle.jpeg"));
//    candy.append(new Element("Миндаль Иванович",":/imgs/Миндаль_Иванович.jpeg"));
//    candy.append(new Element("Чернослив Михайлович",":/imgs/Чернослив_Михайлович.jpeg"));

    selected = -1;
    itemIndex = -1;
}

Groups::~Groups()
{
//    for (Element* el: candy) delete el;
//    for (Element* el: fruits) delete el;
//    for (Element* el: vegetables) delete el;
}

Articles* Groups::itemsModel() {
    Articles* ret;
    if (selected != -1)
        ret = items[name()];
    else
        ret = items["Конфеты"];

    return ret;
}

QString Groups::name()
{
    if (selected != -1)
        return items.keys().at(selected);

    return "Группы";
}

void Groups::curIndex(int i) {
    selected = i;
    nameChanged(name());
}

void Groups::curItem(int i)
{
    itemIndex = i;
    sigCurItem();
}

QHash<int, QByteArray> Groups::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[ItemRole] = "item";
    roles[ItemsModel] = "items";

    return roles;
}

QVariant Groups::headerData(int /*section*/, Qt::Orientation /*orientation*/, int /*role*/) const
{
    // FIXME: Implement me!
    return "Groups";
}

int Groups::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return items.keys().size();
    // FIXME: Implement me!
}

QVariant Groups::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    if (index.row() >= 0)
    if (index.row() < items.keys().size())
        switch (role) {
          case Groups::NameRole: return items.keys().at(index.row());
        }

    return QVariant();
}
