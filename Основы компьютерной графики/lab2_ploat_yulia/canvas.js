var canvas = document.getElementById('canvas');
var context = canvas.getContext('2d');

canvas.width = 800;
canvas.height = 600;

var x;
var y;
var xNull = canvas.width / 2;
var yNull = canvas.height / 2;
var size = 50;
var rotate = 0;
var transferY = 0;
var transferX = 0;

function labelAxis(transferX, transferY, size) 
{
    context.strokeStyle = "black";
    context.lineWidth = 1;
    for (var x = 0; x < canvas.width; x += 50) 
	{
        
        labelX = x * 0.1;
        labelX = labelX.toFixed(0); 
        context.strokeText((labelX / (size * 0.1)).toFixed(1), canvas.width / 2 + 10 + x + transferX, canvas.height / 2 - 5 + transferY);
        context.strokeText((-labelX / (size * 0.1)).toFixed(1), canvas.width / 2 + 10 - x + transferX, canvas.height / 2 - 5 + transferY);
    }

    for (var y = 0; y < canvas.width; y += 50) 
	{
        labelY = y * 0.1;
        labelY = labelY.toFixed(0); 
        context.strokeText((-labelY / (size * 0.1)).toFixed(1), canvas.width / 2 + 10 + transferX, canvas.height / 2 - 5 + y + transferY);
        context.strokeText((labelY / (size * 0.1)).toFixed(1), canvas.width / 2 + 10 + transferX, canvas.height / 2 - 5 - y + transferY);
    }
}

function axis(transferX, transferY, size, rotate) 
{
    context.strokeStyle = "black";
    context.lineWidth = 4;

    context.beginPath();
    context.strokeStyle = "black";
    context.moveTo(0, canvas.height / 2 + transferY);
    context.lineTo(canvas.width, canvas.height / 2 + transferY);
    context.closePath();
    context.stroke();

    context.beginPath();
    context.strokeStyle = "black";
    context.moveTo(canvas.width / 2 + transferX, 0);
    context.lineTo(canvas.width / 2 + transferX, canvas.height);
    context.closePath();
    context.stroke();
}

function gridOX(x, y, transferX, transferY) 
{
    context.beginPath();
    context.strokeStyle = "black";
    context.moveTo(x + transferX, y);
    context.lineTo(x + 1 + transferX, y + 1);
    context.closePath();
    context.stroke();
}

function gridOY(y, x, transferX, transferY) 
{
    context.beginPath();
    context.strokeStyle = "black";
    context.moveTo(y, x + transferY);
    context.lineTo(y + 1, x + 1 + transferY);
    context.closePath();
    context.stroke();
}

function gridFull(transferX, transferY) 
{
    for (var x = canvas.width / 2; x < canvas.width - transferX; x += 50)
        for (var y = canvas.height / 2; y > 0; y -= 5)
            gridOX(x, y, transferX, transferY);
    for (var x = canvas.width / 2; x < canvas.width - transferX; x += 50)
        for (var y = canvas.height / 2; y < canvas.height; y += 5)
            gridOX(x, y, transferX, transferY);
    for (var x = canvas.width / 2; x > 0 - transferX; x -= 50)
        for (var y = canvas.height / 2; y > 0; y -= 5)
            gridOX(x, y, transferX, transferY);
    for (var x = canvas.width / 2; x > 0 - transferX; x -= 50)
        for (var y = canvas.height / 2; y < canvas.height; y += 5)
            gridOX(x, y, transferX, transferY);
    for (var x = canvas.height / 2; x < canvas.height - transferY; x += 50)
        for (var y = canvas.width / 2; y > 0; y -= 5)
            gridOY(y, x, transferX, transferY);
    for (var x = canvas.height / 2; x < canvas.height - transferY; x += 50)
        for (var y = canvas.width / 2; y < canvas.width; y += 5)
            gridOY(y, x, transferX, transferY);
    for (var x = canvas.height / 2; x > 0 - transferY; x -= 50)
        for (var y = canvas.width / 2; y > 0; y -= 5)
            gridOY(y, x, transferX, transferY);
    for (var x = canvas.height / 2; x > 0 - transferY; x -= 50)
        for (var y = canvas.width / 2; y < canvas.width; y += 5)
            gridOY(y, x, transferX, transferY);
}

labelAxis(transferX, transferY, size);
gridFull(transferX, transferY);
axis(transferX, transferY, size);
plot(transferX, transferY, size, rotate);
//---------------------------------------------------------------------------------------------------------------------
function plot(transferX, transferY, size, rotate) 
{
    var x;
    var y;
    context.beginPath();
    context.moveTo( xNull + transferX + x, yNull + transferY);
    for (t = 0; t < 2 * Math.PI; t += 0.01) 
	{
        x = 2 * Math.cos(t) + Math.cos(2 * t);
        y = 2 * Math.sin(t) - Math.sin(2 * t);;
        tempX = x;
        tempY = y;
        x = xNull + transferX + (size) * (tempX * Math.cos(rotate) - tempY * Math.sin(rotate)) 
        y = yNull + transferY + (size) * (tempX * Math.sin(rotate) + tempY * Math.cos(rotate)) 
        context.lineTo(x, y);
    }
    context.strokeStyle = "blue";
    context.stroke();
    context.closePath();
}

document.addEventListener("keydown", function(event) 
		{
            context.clearRect(0, 0, canvas.width, canvas.height);
            labelAxis(transferX, transferY, size);
            gridFull(transferX, transferY);
            axis(transferX, transferY, size);
            plot(transferX, transferY, size, rotate);
			if(event.keyCode == 87) transferY -= 1;			//W
				
			if(event.keyCode == 83) transferY += 1;			//S
			
			if(event.keyCode == 65) transferX += 1;			//A
			
			if(event.keyCode == 68) transferX -= 1;			//D
				
			if(event.keyCode == 82) size += 1	//R
				
			if(event.keyCode == 76) size -= 1	//L
				
			if(event.keyCode == 80) rotate += 0.1;			//P
				
			if(event.keyCode == 79) rotate -= 0.1;		//O
				
		});