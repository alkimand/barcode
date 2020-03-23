import QtQuick 2.12
import QtQuick.Controls 2.12

import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import MyData 1.0

Page {
    id: root
    property TabBar tabBar

    header: Label {
        text: DataGroup.name + ":"
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    ColumnLayout {
        anchors.fill: parent

        ListView {
            id: listView
            Layout.alignment: Qt.AlignCenter | Qt.AlignRight
            Layout.fillHeight: true
            Layout.fillWidth: true
            spacing: 15


            model: DataGroup.itemsModel
            delegate: Component {
                Image {
                    id: img2
                  width: listView.width
//                  height: listView.width
                  fillMode: Image.PreserveAspectFit
                  Layout.fillWidth: true
                  source: image
                  MouseArea {
                      anchors.fill: img2
                      onClicked: {
                          DataGroup.itemsModel.curIndex = index
                          root.tabBar.setCurrentIndex(2)
                      }
                  }
              }
            }
        }
    }
}
