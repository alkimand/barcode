#ifndef INFO_H
#define INFO_H

#include <QObject>

class QQmlEngine;
class QJSEngine;
class QSslKey;
class QSslCertificate;

class Info : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ssl READ ssl NOTIFY sslChanged)
public:
    static QObject *init(QQmlEngine *engine, QJSEngine *scriptEngine);

private:
    explicit Info(QObject *parent = nullptr);

    QSslKey* pkey;
    QSslCertificate* cert;

    QString ssl();

signals:
    void sslChanged(QString ssl);

};

#endif // INFO_H
