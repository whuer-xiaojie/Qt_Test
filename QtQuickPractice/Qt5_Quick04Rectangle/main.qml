import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    //设置主窗口背景颜色
    color: "black"
    title: qsTr("Hello World")

    MouseArea {
        anchors.fill: parent
        onClicked: {

        }
    }
   Rectangle{
       width: 320
       height: 480
       //指定填充颜色
       //color: "red"

       //旋转90度，就是实现水平渐变
       //rotation:90
       //渐变颜色设置  垂直方向的渐变（默认）
       gradient: Gradient{
           GradientStop{ position: 0.0;color:"red";}
           GradientStop{ position: 0.5;color:"yellow"}
           GradientStop{ position: 1;color:"green"}
       }


       border.color: "#454545"
       border.width: 5
       radius: 12

   }
   MyGroupItem{
   }
    Text {
        //设置文本中内容颜色
        color:"green"
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}
