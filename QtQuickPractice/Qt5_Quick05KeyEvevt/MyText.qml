import QtQuick 2.0

Item {
    Rectangle{
        id:myTextRect
        Text {
            id: nomal
            anchors.left: parent.left
            anchors.leftMargin: 6
            anchors.top: parent.top
            anchors.topMargin: 5
            font.pixelSize: 24
            text:"Nomal Text"
        }
        Text {
            id: raisedText
           anchors.left: nomal.right
           anchors.leftMargin: 10
           anchors.top: parent.top
           anchors.topMargin: 5
           font.pixelSize: 24
            text: "raised Style Text"
           //设置文本字体
            style: Text.Raised
            //设置字体轮廓颜色
            styleColor: "blue"
        }
        Text {
            id: outLineText
            anchors.top:nomal.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 6
            font.pixelSize: 24
            text: "Outline Text  哈哈哈"
            style:Text.Outline
            styleColor: "red"
        }
        Text {
            id: sunkenText
            anchors.left: outLineText.right
            anchors.leftMargin: 10
            anchors.top: raisedText.bottom
            anchors.topMargin: 10
             font.pixelSize: 24
            text: "Sunken Text"
            style: Text.Sunken

        }
    }

}
