import QtQuick 2.5

Item {
    id:coverFlow



    property ListModel model

    property int itemCount:5



    PathView{

       id:pathView



       model:coverFlow.model

       delegate:Delegate{
       }

       path:coverFlowPath

       pathItemCount:coverFlow.itemCount

       anchors.fill:parent

    }



    Path{

       id:coverFlowPath

       startX:0

       startY:coverFlow.height/3



       PathLine{x:coverFlow.width*0.5;y:coverFlow.height/3;  }

       PathPercent{value:0.50}



       PathLine{x:coverFlow.width;y:coverFlow.height/3;}

       PathPercent{value:1.0}

    }


}
