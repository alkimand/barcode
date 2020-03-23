import QtQuick 2.0
import QtQuick.Controls 2.12

import QtQuick.Layouts 1.12

import MyData 1.0

RowLayout {
    id: root
    property TabBar tabBar

//    Layout.fillWidth: true
    Button {
       text: (index+1) + ". " + name
       onClicked: {
           DataGroup.curIndex = index;
           root.tabBar.setCurrentIndex(1)
       }
    }
}
