import QtQuick 2.12
import QtQuick.Controls 2.12

import MyData 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tabs")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Group {
            tabBar: tabBar
        }
        Page1 {
            tabBar: tabBar
        }
        Page2 {}
    }

    footer: TabBar {
        id: tabBar
        TabButton {
            id: tab1
            text: DataGroup.name
        }
        currentIndex: swipeView.currentIndex

        TabButton {
            id: tab2
            text: qsTr("Page 1")
        }
        TabButton {
            id: tab3
            text: qsTr("Page 2")
        }
    }
}
