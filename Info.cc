#include "Info.h"

#include <QSslKey>
#include <QSslCertificate>
#include <QSslSocket>
#include <QFile>

static QString err;
//static QByteArray readFile(QString file) {
//    QFile f(file);
//    if (f.open(QIODevice::ReadOnly))
//    return file
//}

QObject *Info::init(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    static Info* info = new Info();
    return info;


}

Info::Info(QObject *parent) : QObject(parent)
{
//    QSslCertificate mySsl();
    QList<QSslCertificate> certs;

    QFile fCA(":/cert/rootCA.pem");
          fCA.open(QFile::ReadOnly);
    QSslCertificate rootCA = QSslCertificate(&fCA);
    fCA.close();

    QFile fServer(":/cert/server.crt");
          fServer.open(QFile::ReadOnly);
    QSslCertificate serverCert = QSslCertificate(&fServer);
    fServer.close();

    QFile aa("/home/android/my/server101.mycloud.csr");
          aa.open(QFile::ReadOnly);
    QSslCertificate aaCert = QSslCertificate(&aa);
    aa.close();


    QList<QSslCertificate> w;
    w << rootCA << serverCert << aaCert;
    qInfo() << "rootCA:    " << rootCA;
    qInfo() << "serverCert:" << serverCert;
//    qInfo() << "w:" << w;
//    err = QSslCertificate::verify(QList<QSslCertificate>() << serverCert)[0].errorString();
    err = rootCA.expiryDate().toString();
    qInfo() << "verify:" << QSslCertificate::verify(QList<QSslCertificate>() << serverCert);

//    certs << QSslCertificate::fromPath(":/cert/rootCA.pem");
//    qInfo() << certs;
//    QSslCertificate ca_cert = handle_certificate("/cert/ca.crt");



    certs << QSslCertificate(":/cert/server.pem");
    qInfo() << certs;
    certs.append(QSslCertificate::fromPath(":/cert/client.pem"));
    qInfo() << certs;
    QSslCertificate clientCert = QSslCertificate(":/cert/client.pem");
    qInfo() << clientCert.verify(certs);
//    qInfo() << "SSL" << certs.verify(clientCert);
}

QString Info::ssl() {
//    return QSslCertificate::ssl
//    const QByteArray ver = QSslCertificate::version();
    if (QSslSocket::supportsSsl())
        return err;

    return "QSslSocket::supportsSsl(): NO";
}
