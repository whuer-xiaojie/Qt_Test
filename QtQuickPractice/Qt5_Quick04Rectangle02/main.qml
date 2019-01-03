import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    /*
    Rectangle{
        id:rect
        color: "white"
        anchors.fill: parent
        border.color: " red"
        border.width: 5
    }
    */
    //MyRectangle{

  //  }

    MyRectangle1{

    }

    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}
