import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1100
    height:900
    title: qsTr("PathView")
    ListModel{
        id:model
        ListElement{url:"../backImage/home"}
        ListElement{url:"../backImage/image1"}
        ListElement{url:"../backImage/image2"}
        ListElement{url:"../backImage/image3"}
        ListElement{url:"../backImage/image4"}
        ListElement{url:"../backImage/image5"}
    }
    CoverFlow {
        anchors.fill: parent
        model:model
        }
}

