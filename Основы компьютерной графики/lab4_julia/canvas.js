var canvas = document.getElementById('canvas');
var ctx = canvas.getContext('2d');

let pointsArr = [300,600,500,700,700,750,750,500,700,400,600,500,300,300];
let indexesArr = earcut(pointsArr);
let result = [];

for(let i = 0; i < indexesArr.length; i++) {
    result.push( pointsArr[ indexesArr[i] * 2 ] );
    result.push( pointsArr[ indexesArr[i] * 2 + 1 ] );
}

function drawRect(bitMap, color) {
    for (var i = 0; i < bitMap.length; i = i + 2)
        if (i == 0) ctx.moveTo(bitMap[i], bitMap[i+1]);
        else ctx.lineTo(bitMap[i], bitMap[i+1]);
    ctx.closePath();
    ctx.strokeStyle = color;
    ctx.stroke();
}

function drawTriangle(bitMap) {
    ctx.beginPath();
    ctx.moveTo(bitMap[0], bitMap[1]);
    ctx.lineTo(bitMap[2], bitMap[3]);
    ctx.lineTo(bitMap[4], bitMap[5]);
    ctx.closePath();
    ctx.stroke();

    for (var i = 6; i <= bitMap.length - 6; i+=6) {
        ctx.beginPath();
        ctx.lineTo(bitMap[i], bitMap[i+1]);
        ctx.lineTo(bitMap[i+2], bitMap[i+3]);
        ctx.lineTo(bitMap[i+4], bitMap[i+5]);
        ctx.closePath();
        ctx.stroke();
    }
}

x = [];
y = [];
j = 0;
S = 0;
for(i=0; i<pointsArr.length; i+=2) {
  x[j] = pointsArr[i];
  y[j] = pointsArr[i+1];
  j++;
}

mousex = canvas.width + 10;
mousey = canvas.height + 10;
canvas.onmousemove = function(event)
{
	tempcoorX = event.offsetX;
	tempcoorY = event.offsetY;
	mousex = tempcoorX;
	mousey = tempcoorY;
}

function inPoly(xp, yp, x, y)
{
	npol = xp.length;
	j = npol - 1;
	var c = 0;
	for (i = 0; i < npol; i++)
	{
		if ((((yp[i] <= y) && (y < yp[j])) || ((yp[j] <= y) && (y < yp[i]))) &&
			(x > (xp[j] - xp[i]) * (y - yp[i]) / (yp[j] - yp[i]) + xp[i]))
		{
			c = !c
		}
		j = i;
  }
  
	return c;
}

drawRect(pointsArr, 'black');
drawTriangle(result);

function pictures()
{
		canvas.onmousedown = function(event)
	  {
      if (inPoly(x,y, mousex, mousey) != 0)
	    {
		    document.getElementById('out').innerHTML = "Точка лежит в многоугольнике!";
	    }
  }

	requestAnimation = requestAnimationFrame(pictures);
}

requestAnimationFrame(pictures);
        

