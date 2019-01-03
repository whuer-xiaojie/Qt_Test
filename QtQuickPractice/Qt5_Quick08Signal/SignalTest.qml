import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1

Item {
    id:signalTest
    anchors.fill: parent
    Text{
        id:text1
        anchors.centerIn: parent
        font.pixelSize: 24
        text:"Text One"

    }
    Text{
        id:text2
        font.pixelSize:24
        anchors.top: text1.bottom
        anchors.topMargin: 5
        anchors.left: text1.left
        text:"Text Tow"
    }
    //设置button的样式
    Component{
        id:buttonStyle
        ButtonStyle{
            background:  Rectangle{
                implicitWidth :100
                implicitHeight: 35
                radius: 5
                border.width: control.pressed?2:1;
                border.color: (control.hovered || control.pressed)?"green":"red";
            }

        }
    }

    Button{
        id:changeButton
        text:"change"
        anchors.top: text2.bottom
        anchors.topMargin: 5
        anchors.left: text2.left
        style: buttonStyle
    }
    //信号处理
    Connections{
        //信号发出对象
        target: changeButton
        //收到的信号和做出的响应
        onClicked:{
            //文本1的字体颜色随机变化
            text1.color=Qt.rgba(Math.random()%255,Math.random()%255,Math.random()%255,1);
            //文本2的字体颜色随机变化
            text2.color=Qt.rgba(Math.random()%255,Math.random()%255,Math.random()%255,1);
        }
    }

}
