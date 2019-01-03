import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1100
    height:900
    //title: qsTr("PathView")
    ListModel{
        id:model
        ListElement{url:":/new/prefix1/backImage/image1.jpg"}
        ListElement{url:":/new/prefix1/backImage/image2.jpg"}
        ListElement{url:":/new/prefix1/backImage/image3.jpg"}
        ListElement{url:":/new/prefix1/backImage/image4.jpg"}
        ListElement{url:":/new/prefix1/backImage/image5.jpg"}
        //ListElement{url:":/new/prefix1/backImage/home.jpg"}
    }
    CoverFlow {
        anchors.fill: parent
        model:model
        }

/*
    MainForm {
        anchors.fill: parent
       //mouseArea.onClicked: {
           // Qt.quit();
        //}
    }
    */

}
