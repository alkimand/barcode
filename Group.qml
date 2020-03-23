import QtQuick 2.0
import QtQuick.Controls 2.12

import QtQuick.Layouts 1.12

import MyData 1.0

Page {
    id: root
    property TabBar tabBar

    header: Label {
        text: qsTr("Выберите группу")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    ColumnLayout {
        anchors.fill: parent

        ListView {
            Layout.alignment: Qt.AlignCenter | Qt.AlignRight
            Layout.fillHeight: true
            Layout.fillWidth: true

            model: DataGroup
            delegate: GroupDelegate{tabBar: root.tabBar}
        }
//        Text {
//            id: name
//            text: MyInfo.ssl
//        }
    }

}
