import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1
Item {
    id:mySignal1
    anchors.fill: parent
    Text{
        id:myText
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.verticalCenter: parent.verticalCenter
        text:"My Custom Signal and Slot"
        font.pixelSize: 30
    }
    //设置统一样式
    Component{
        id:buttonStyle
        ButtonStyle{
            background:Rectangle{
                implicitHeight: 50
                implicitWidth: 70
                radius: 5
                border.width:  (control.hovered |control.pressed)?2:1
            }
        }
    }
    Button{
        id:button1
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.horizontalCenter: parent.horizontalCenter
        style:buttonStyle
        text:"red"
        onClicked: {
            myText.color='red'

        }
    }
    Button{
        id:button2
        anchors.left: button1.right
        anchors.leftMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        style:buttonStyle
        text:'green'
        onClicked: {
            myText.color="green"
        }
    }

}
