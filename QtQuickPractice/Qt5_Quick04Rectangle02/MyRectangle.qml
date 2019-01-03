import QtQuick 2.0

Item {
    id:myRectangle


    Rectangle{
        id:rect1
        width: 300
        height: 250
        //布局
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 5
        gradient: Gradient{
            GradientStop{ position: 0;color:"red";}
            GradientStop{ position: 0.5;color:"green";}
        }
    }
    Rectangle{
        id:rect2
        //布局
        anchors.left: rect1.right
        anchors.leftMargin: 15
        anchors.top: parent.top
        anchors.topMargin: 5
        //大小
        width:300
        height:250
        //颜色渐变
        gradient: Gradient{
            GradientStop{ position: 0;color:"yellow";}
            GradientStop{ position: 0.5;color:"black"; }
        }
    }
    Rectangle{
        id:rect3
        anchors.centerIn: parent
        width: 100
        height: 100
        antialiasing: true;
    }
}
