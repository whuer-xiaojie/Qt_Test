import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
   MyMouseSignal{
   }
    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}
