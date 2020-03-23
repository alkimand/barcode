#include "Articles.h"

Article::Article(QString tmpName, QString tmpImg, QString tmpBarcode) {
    name = tmpName;
    img = tmpImg;
    barcode = tmpBarcode;
}

QString Article::getName() const {
    return name;
}

QString Article::getImg() const {
    return img;
}

QString Article::getBarcode() const {
    return barcode;
}
