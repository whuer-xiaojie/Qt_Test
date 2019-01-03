import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
   //MyEvent{
 //  }
    MyText{

    }

    Text {
       //wrapMode: Text.WordWrap;
       font.bold: true;
       font.pixelSize: 20
       font.underline: true;
       text:"Hello <font color=\"blue\"> Blue</font> Text"

        anchors.centerIn: parent
      //  color:"blue"
    }
    Button{
        text:"quit"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        onClicked: Qt.quit()
    }
}
