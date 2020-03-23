#ifndef ARTICLES_H
#define ARTICLES_H

#include <QAbstractListModel>
#include "Item.h"

class Article {
  private:
    QString name,
            img,
            barcode;

  public:
    Article (QString tmpName, QString tmpImg, QString tmpBarcode);
    QString getName() const;
    QString getImg() const;
    QString getBarcode() const;
};

class Articles : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(int curIndex WRITE curIndex)
    Q_PROPERTY(QString barcode READ barcode NOTIFY sigBarcode)
  public:
    explicit Articles(QObject *parent = nullptr);
    ~Articles();
    enum PkgRoles {
        NameRole = Qt::UserRole + 1,
        ImageRole
    };
    QHash<int, QByteArray> roleNames() const;

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void append(Article* article) {
        items.append(article);
    }

  private:
    int selected;

//    QStringList list;
    QList<Article*> items;
    QString m_name;
    QString m_barcode;

    QString name();
    QString barcode() const;
    void curIndex(int i);

signals:
    void nameChanged(QString name);
    void sigBarcode();
};

#endif // ARTICLES_H
