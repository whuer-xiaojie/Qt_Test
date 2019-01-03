import QtQuick 2.0
import QtQuick.Controls 1.1

Item {
    id:myImage
    anchors.fill: parent
    /*
    Image{
        id:localImage
        //anchors.centerIn: parent
        source: "qrc:/new/prefix1/backImage/home.jpg"

    }
    */
    BusyIndicator{
        id:busy
        running:true;
        anchors.centerIn: parent;
        z:2

    }
    Label{
        id:stateLabel
        visible: false
        anchors.centerIn: parent
        z:3
    }
    Image{
        id:webImage
        //异步加载，网络资源默认自动异步加载，只有本地需要异步加载时才设置
        asynchronous: true;
        //不用缓存图片
        cache:false
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        onStateChanged: {
            if(webImage.status==Image.Loading)
            {
                busy.running=true;
                stateLabel.visible=false;
             }
            else if(webImage.status==Image.Ready)
            {
                busy.running=false;
            }
            else if(webImage.status==Image.Null)
            {
                busy.running=false;
                stateLabel.visible=true;
                stateLabel.text="Error";
            }
        }
    }
    Component.onCompleted: {
        webImage.source=":/new/prefix1/backImage/image5.jpg"
}
}
