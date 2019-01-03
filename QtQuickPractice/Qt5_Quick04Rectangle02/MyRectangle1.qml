import QtQuick 2.0

Item {
    id:myRectangle1
    Rectangle{
       color: "green"
        x:20
        y:20
        width: 200
        height: 200
        z:0.5

    }
    Rectangle {
        width: 100;
        height: 100;
       anchors.centerIn: parent;
       color: "#a0c080";
        z: 0.2;
       opacity: 0.6;
    }


}
