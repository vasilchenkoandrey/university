var canvas = document.getElementById('canvas');
var context = canvas.getContext('2d');
var requestAnimation;
var pi = Math.PI;

var fxS = 0.2;
var fyS = 1.8;
var fxF = 0.8;
var fyF = 1.2;



var coorS = {
    x:100,
    y:300,
    angS:pi*fxS,
    angF:pi*fyS,
    r:50
}
var coorF = {
    x:300,
    y:300,
    angS:pi*fxF,
    angF:pi*fyF,
}

xEye=coorS.x;
yEye=275;
rEye=10;
smileX = 750;
smileControlX = 700;
 smileControlY = 300;
  smileEndX = 700;
     smileEndY = 290;
var bool = false;

function pictures() {
    context.clearRect(0, 0, canvas.width, canvas.height);

    context.fillStyle = "#fff";
    for (i=200;i<700;i=i+30)
    {
        context.fillRect(i, 295, 10, 10);
    }
    
    context.beginPath();
    context.arc(coorS.x, coorS.y, coorS.r, coorS.angS, coorS.angF, false);
    context.fillStyle = "#000";
    context.fillRect(coorS.x, coorS.y-5, -600, 20);
    context.lineTo(coorS.x, coorS.y);
    context.closePath();
    context.fillStyle = "#FF0";
    context.fill();
    context.stroke();
    context.closePath();

    context.beginPath();
    context.arc(xEye, 275, rEye, 0, 2 * Math.PI);
    context.fillStyle = "#000";
    context.fill();
    context.closePath();

    
    if (coorS.x+coorS.r < canvas.width && bool == false)
    {
        coorS.x++;
        xEye++;
        
        if (coorS.x+coorS.r >= canvas.width) 
        {
            bool = true;
        }
    }
    else
    {
        smileX--;
        smileControlX--;
        smileEndX--;
        coorS.x--;
        xEye--;
        if (coorS.x-coorS.r == 0)
        {
            smileX = 750;
            smileControlX = 700;
            smileControlY = 300;
            smileEndX = 700;
            smileEndY = 290;
            bool = false;
        }
    }

    if (bool == true)
    {
        context.clearRect(0, 0, canvas.width, canvas.height);
        context.beginPath();
        context.arc(coorS.x, coorS.y, coorS.r, 0, 2*pi, true);
        context.lineTo(coorS.x, coorS.y);
        context.closePath();
        context.fillStyle = "#FF0";
        context.fill();
        context.closePath();
        context.beginPath();
        context.arc(xEye, yEye, rEye, 0, 2 * Math.PI);
        context.fillStyle = "#000";
        context.fill();
        context.closePath();
        context.beginPath();
        context.moveTo(smileX, coorS.y);
        context.quadraticCurveTo(smileControlX, 300, smileEndX, 290); 
        context.lineWidth = 2;
        context.strokeStyle = "black";                                    
        context.stroke();

    }

    
    

    requestAnimation = requestAnimationFrame(pictures);
}

requestAnimationFrame(pictures);

