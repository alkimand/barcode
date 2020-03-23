#include "Articles.h"



Articles::Articles(QObject *parent)
    : QAbstractListModel(parent)
{
    m_barcode = "EAN13/1.gif";
//    list.append("Фрукты");
//    list.append("Овощи");
//    list.append("Конфеты");

//    candy.append(new Element("O'Rera Truffle",":/imgs/O'Rera_Truffle.jpeg"));
//    candy.append(new Element("Миндаль Иванович",":/imgs/Миндаль_Иванович.jpeg"));
//    candy.append(new Element("Чернослив Михайлович",":/imgs/Чернослив_Михайлович.jpeg"));

    selected = -1;
}

Articles::~Articles()
{
//    for (Element* el: candy) delete el;
//    for (Element* el: fruits) delete el;
//    for (Element* el: vegetables) delete el;
}

QString Articles::name()
{
    return m_name;
}

QString Articles::barcode() const
{
    return m_barcode;
}

void Articles::curIndex(int i) {
    selected = i;
    m_barcode = items.at(i)->getBarcode();
    sigBarcode();
}

QHash<int, QByteArray> Articles::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[ImageRole] = "image";

    return roles;
}


QVariant Articles::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    return "Groups";
}

int Articles::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return items.size();
    // FIXME: Implement me!
}

QVariant Articles::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    if (index.row() >= 0)
    if (index.row() < items.size())
        switch (role) {
          case NameRole: return items.at(index.row())->getName();
          case ImageRole: return items.at(index.row())->getImg();
        }

    return QVariant();
}

