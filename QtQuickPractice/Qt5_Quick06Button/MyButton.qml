import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1
Item{
    id:myButton
    anchors.fill: parent

    //统一设定按钮Button的style
    Component{
        id:styleButton
       ButtonStyle{
            background: Rectangle{
                //按钮大小为70*25
                implicitWidth: 70
                implicitHeight: 25
                radius: 5
                //按钮被按下边框为2否则为1
                border.width: control.pressed?2:1
                //按钮被选中或者被按下边框为绿色否则为红色
                border.color: (control.hovered || control.pressed)?"green":"red"
            }
        }

    }

    Button{
        id:myButton0
        text:"确定"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        //使用统一样式
        style:styleButton
    }

Button{
    id:myButton1
        text:"退出"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        //自定义样式
        style: ButtonStyle{
            //重写background
            background: Rectangle{
                //按钮大小为70*25
                implicitWidth: 70
                implicitHeight: 25
                radius: 5
                //按钮被按下边框为2否则为1
                border.width: control.pressed?2:1
                //按钮被选中或者被按下边框为绿色否则为红色
                border.color: (control.hovered || control.pressed)?"green":"red"
            }

        }
    }

}


