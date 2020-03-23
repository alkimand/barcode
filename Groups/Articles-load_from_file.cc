void Articles::load_from_file(QString file) {
    QFile csv(file);
    csv.open(QIODevice::ReadOnly | QIODevice::Text);
    
    QString group;
    QMap<QString, QList<Items>> shop;
    while (!csv.atEnd()) {
        QString line = csv.readLine();//.trimmed();
        
        if (line.at(0) != '\t') {
            group = line.trimmed();
            shop[group] = QList<Items>();
        }
        else {
            QStringList list = line.split('\t');
            shop[group].append(Items(list[1].trimmed(),
                               list[2].trimmed()));
        }
    }
    
}

