import QtQuick 2.0

Item {
    id:myMouseSignal
    anchors.fill: parent
    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            if(mouse.button==Qt.RightButton)
            {
                //Qt.quit();
                 color="black";
            }
            if(mouse.button==Qt.LeftButton)
            {
                color=Qt.rgba(Math.random()%255,Math.random()%255,Math.random()%255,1);
            }
         }
        onDoubleClicked: {
            color=Qt.black;
        }
    }

}
