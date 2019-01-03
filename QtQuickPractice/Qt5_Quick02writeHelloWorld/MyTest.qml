import QtQuick 2.0

Rectangle{
        width:100
        height:100
       anchors.fill: parent

        Text{
            text:"hello world"
            anchors.centerIn: parent
        }
        MouseArea{
             anchors.fill: parent
             onClicked: {
                 Qt.quit()
             }
        }
 }

