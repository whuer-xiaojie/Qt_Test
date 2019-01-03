import QtQuick 2.0
import QtQuick.Controls 1.1

Item {
    id:mySignal
    anchors.fill: parent
    Text{
        id:text1
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.horizontalCenter: parent.horizontalCenter
        text:"Custom Signal Test Text"
        font.pixelSize: 30
    }
    Component{
        id:colorComponent
        Rectangle{
            width: 60
            height: 35
            id:colorSet
            //设置信号
            signal colorPicked(color clr)
            MouseArea{
                //设置信号区域
                anchors.fill: parent
                //在信号区域鼠标被按下发出信号
                onPressed: colorSet.colorPicked(colorSet.color)
            }
        }
    }
    //动态创建组件
    Loader{
        id:redLoader
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        //指定组件
        sourceComponent: colorComponent
        //信号处理器给组件设置颜色
        onLoaded: {
            item.color="red"
        }
    }
    Loader{
        id:blueLoader
        anchors.left: redLoader.right
        anchors.leftMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        sourceComponent: colorComponent
        onLoaded: {
            item.color="blue"
        }
    }
    Connections{
        //对象是动态链接创建的组件
        target:redLoader.item
        onColorPicked:{
            text1.color= clr
        }
    }
    Connections{
        target:blueLoader.item
        onColorPicked:{
            text1.color=clr
        }
    }


}
