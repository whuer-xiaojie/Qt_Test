import QtQuick 2.0

Rectangle {
    id:myGroupItem
    Rectangle{
        x:325
        y:0
        width: 300
        height: 235
        gradient: Gradient{
            GradientStop{ position: 0;color:"#026548";}
            GradientStop{ position: 0.5;color:"#231365";}
            GradientStop{ position: 1;color:"#987454";}
        }
        border.color: "#454545"
        border.width: 5
        radius: 12
    }
    Rectangle{
        x:325
        y:240
        width: 300
        height: 230
        //rotation: 90
        gradient:Gradient{
            GradientStop{ position: 0;color:"blue";}
            GradientStop{ position: 1;color:"#987566";}
        }
        border.color: "#454545"
        border.width: 5
        radius: 12
    }
}



/*
Rectangle {
   //width: 300;
   // height: 200;
   Item {
       id: gradientGroup;
      Rectangle {
          x:325
          y:0
          width: 300
          height: 235
           gradient: Gradient {
                GradientStop { position: 0.0; color: "#202020"; }
             GradientStop { position: 1.0; color: "#A0A0A0"; }
           }
      }

     Rectangle {
         x:325
         y:240
         width: 230
         height: 300
         rotation: 90
           gradient: Gradient {
            GradientStop { position: 0.0; color: "#202020"; }
               GradientStop { position: 1.0; color: "#A0A0A0"; }
         }
        }
    }

  Component.onCompleted: {
       console.log("visible children: " ,gradientGroup.visibleChildren.length);
        console.log("visible children: " ,gradientGroup.children.length);
     for(var i = 0; i < gradientGroup.children.length; i++){
        console.log("child " , i, " x = ", gradientGroup.children[i].x);
        }
    }
}

*/


