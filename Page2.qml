import QtQuick 2.12
import QtQuick.Controls 2.5

import MyData 1.0

Page {
    Image {
        anchors.centerIn: parent
//        id: name
        fillMode: Image.PreserveAspectFit
        source: DataGroup.itemsModel.barcode
    }
}
