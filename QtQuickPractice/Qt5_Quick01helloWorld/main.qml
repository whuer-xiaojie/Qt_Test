import QtQuick 2.5
import QtQuick.Window 2.2

//根对象
Window {
    visible: true//Window的属性
    width: 640
    height: 480
    title: qsTr("Hello World")
//子对象
    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            Qt.quit();
        }
    }
}
