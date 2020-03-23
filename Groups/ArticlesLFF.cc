//#include "Articles.h"

//#include <QFile>

//#include <QDebug>

//Articles* Articles::load_from_file(QString file) {
//    QFile csv(file);
//    csv.open(QIODevice::ReadOnly | QIODevice::Text);

//    QString group;
//    QMap<QString, QList<Article>> shop;
//    while (!csv.atEnd()) {
//        QString line = csv.readLine();
        
//        if (line.at(0) != '\t') {
//            group = line.trimmed();
//            shop[group] = QList<Article>();
//        }
//        else {
//            QStringList list = line.split('\t');
//            shop[group].append(Article(list[1].trimmed(),
//                               list[2].trimmed()));
//        }
//    }

////    for (Article item: shop["Конфеты"])
////        qInfo() << item.getName() << item.getImg();

////    for (QString s: shop.keys())
////        qInfo() << "key:" << s;

//    return nullptr;//new Articles(shop);
//}
