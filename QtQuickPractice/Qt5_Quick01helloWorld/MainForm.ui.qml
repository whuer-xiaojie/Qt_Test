import QtQuick 2.5
//根对象是一个矩形
Rectangle {
    //申明一个新的mouseArea属性，作为子对象MouseArea的ID属性的属性别名
    property alias mouseArea: mouseArea

    width: 360
    height: 360
//MouseArea是一个不可见项目，为他覆盖的课件项目提供鼠标处理
    MouseArea {
        //ID属性作为该对象的标识，在其他地方可以通过id来引用该对象
        id: mouseArea
        //这个属性起到布局的作用，这里是填充整个父对象
        anchors.fill: parent
    }
//文本子项目text ，用来显示文本内容
    Text {
        //使文本位于父对象的中心位置
        anchors.centerIn: parent
        //文本内容
        text: "Hello World"
    }
}
