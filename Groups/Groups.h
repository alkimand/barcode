#ifndef GROUPS_H
#define GROUPS_H

#include <QAbstractListModel>
#include "Item.h"

class QQmlEngine;
class QJSEngine;
class Articles;

class Groups : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(Articles* itemsModel READ itemsModel NOTIFY nameChanged)
    Q_PROPERTY(int curIndex WRITE curIndex)
    Q_PROPERTY(int curItem WRITE curItem NOTIFY sigCurItem)
public:
    enum PkgRoles {
        NameRole = Qt::UserRole + 1,
        ItemRole, ItemsModel
    };
    QHash<int, QByteArray> roleNames() const;
    static QObject *init(QQmlEngine *engine, QJSEngine *scriptEngine);
    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    explicit Groups(QObject *parent = nullptr);
    ~Groups();
    int selected;
    int itemIndex;
    QStringList list;
    static bool m_status;
    QMap<QString,Articles*> items;
    Articles* itemsModel();
//    QList<Element*> candy,
//                    fruits,
//                    vegetables;
    QString name();
    void curIndex(int i);
    void curItem(int i);

signals:
    void nameChanged(QString name);
    void sigCurItem();
};

#endif // GROUPS_H
