var canvas = document.getElementById('canvas');
var ctx = canvas.getContext('2d');

canvas.width = document.body.clientWidth;
canvas.height = document.body.clientHeight;

var x;
var y;
var xNull = canvas.width / 2;
var yNull = canvas.height / 2;
var size = 10;
var rotate = 0;
var transferY = 0;
var transferX = 0;
var transferFuncY = 0;
var transferFuncX = 0;

//label axis
function labelAxis(transferX, transferY, size) {
    //OX
    ctx.strokeStyle = "black";
    ctx.lineWidth = 1;
    for (var x = 0; x < canvas.width; x += 50) {
        ctx.font = '12px Segoe UI';
        labelX = x * 0.1;
        labelX = labelX.toFixed(0); //toFixed - char after comma
        ctx.strokeText((labelX / (size * 0.1)).toFixed(1), canvas.width / 2 + 10 + x + transferX, canvas.height / 2 - 5 + transferY);
        ctx.strokeText((-labelX / (size * 0.1)).toFixed(1), canvas.width / 2 + 10 - x + transferX, canvas.height / 2 - 5 + transferY);
    }

    for (var y = 0; y < canvas.width; y += 50) {
        labelY = y * 0.1;
        labelY = labelY.toFixed(0); //toFixed - char after comma
        ctx.strokeText((-labelY / (size * 0.1)).toFixed(1), canvas.width / 2 + 10 + transferX, canvas.height / 2 - 5 + y + transferY);
        ctx.strokeText((labelY / (size * 0.1)).toFixed(1), canvas.width / 2 + 10 + transferX, canvas.height / 2 - 5 - y + transferY);
    }
}

//axis
function axis(transferX, transferY, size, rotate) {
    ctx.strokeStyle = "#6B90D4";
    ctx.lineWidth = 4;
    //OX
    ctx.beginPath();
    ctx.strokeStyle = "#6B90D4";
    ctx.moveTo(0, canvas.height / 2 + transferY);
    ctx.lineTo(canvas.width, canvas.height / 2 + transferY);
    ctx.closePath();
    ctx.stroke();
    //OY
    ctx.beginPath();
    ctx.strokeStyle = "#6B90D4";
    ctx.moveTo(canvas.width / 2 + transferX, 0);
    ctx.lineTo(canvas.width / 2 + transferX, canvas.height);
    ctx.closePath();
    ctx.stroke();
}

//grid X
function gridOX(x, y, transferX, transferY) {
    ctx.beginPath();
    ctx.strokeStyle = "#6B90D4";
    ctx.moveTo(x + transferX, y);
    ctx.lineTo(x + 1 + transferX, y + 1);
    ctx.closePath();
    ctx.stroke();
}

//grid Y
function gridOY(y, x, transferX, transferY) {
    ctx.beginPath();
    ctx.strokeStyle = "#6B90D4";
    ctx.moveTo(y, x + transferY);
    ctx.lineTo(y + 1, x + 1 + transferY);
    ctx.closePath();
    ctx.stroke();
}

//grid full
function gridFull(transferX, transferY) {
    //OY
    // right-top
    for (var x = canvas.width / 2; x < canvas.width - transferX; x += 50)
        for (var y = canvas.height / 2; y > 0; y -= 5)
            gridOX(x, y, transferX, transferY);
    // right-bottom
    for (var x = canvas.width / 2; x < canvas.width - transferX; x += 50)
        for (var y = canvas.height / 2; y < canvas.height; y += 5)
            gridOX(x, y, transferX, transferY);
    // left-top
    for (var x = canvas.width / 2; x > 0 - transferX; x -= 50)
        for (var y = canvas.height / 2; y > 0; y -= 5)
            gridOX(x, y, transferX, transferY);
    // left-bottom
    for (var x = canvas.width / 2; x > 0 - transferX; x -= 50)
        for (var y = canvas.height / 2; y < canvas.height; y += 5)
            gridOX(x, y, transferX, transferY);

    //OX
    // right-top
    for (var x = canvas.height / 2; x < canvas.height - transferY; x += 50)
        for (var y = canvas.width / 2; y > 0; y -= 5)
            gridOY(y, x, transferX, transferY);
    // right-bottom
    for (var x = canvas.height / 2; x < canvas.height - transferY; x += 50)
        for (var y = canvas.width / 2; y < canvas.width; y += 5)
            gridOY(y, x, transferX, transferY);
    // left-top
    for (var x = canvas.height / 2; x > 0 - transferY; x -= 50)
        for (var y = canvas.width / 2; y > 0; y -= 5)
            gridOY(y, x, transferX, transferY);
    // left-bottom
    for (var x = canvas.height / 2; x > 0 - transferY; x -= 50)
        for (var y = canvas.width / 2; y < canvas.width; y += 5)
            gridOY(y, x, transferX, transferY);
}

labelAxis(transferX, transferY, size);
gridFull(transferX, transferY);
axis(transferX, transferY, size);
plot(transferX, transferY, transferFuncX, transferFuncX, size, rotate);

function plot(transferX, transferY, transferFuncX, transferFuncY, size, rotate) {
    var x;
    var y;
    ctx.beginPath();
    ctx.moveTo(xNull + transferX + transferFuncX, yNull + transferY + transferFuncY);
    for (t = 0; t < 5 * Math.PI; t += 0.01) {
        x = t * Math.sin(t);
        y = -t * Math.cos(t);
        tempX = x;
        tempY = y;
        x = xNull + transferX + transferFuncX + (size) * (tempX * Math.cos(rotate) - tempY * Math.sin(rotate)) //rotate X 
        y = yNull + transferY + transferFuncY +(size) * (tempX * Math.sin(rotate) + tempY * Math.cos(rotate)) //rotate Y
        ctx.lineTo(x, y);
    }
    ctx.strokeStyle = "#FF0000";
    ctx.stroke();
    ctx.closePath();
}

canvas.onmousemove = function(event) {
    var coorMouseX = event.offsetX;
    var coorMouseY = event.offsetY;
    document.getElementById('mouseCoor').innerHTML = 'X: ' + coorMouseX + '  |   Y: ' + coorMouseY;
}

transferX = document.getElementById("X");
transferY = document.getElementById("Y");
transferFuncX = document.getElementById("FUNCX");
transferFuncY = document.getElementById("FUNCY");
size = document.getElementById("SIZE");
rotate = document.getElementById("ROTATE");

addEventListener("input", function() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    labelAxis(parseFloat(transferX.value),
        parseFloat(transferY.value),
        parseFloat(size.value),
        parseFloat(rotate.value));

    gridFull(parseFloat(transferX.value),
        parseFloat(transferY.value));

    axis(parseFloat(transferX.value),
        parseFloat(transferY.value));

    plot(parseFloat(transferX.value),
        parseFloat(transferY.value),
        parseFloat(transferFuncX.value),
        parseFloat(transferFuncY.value),
        parseFloat(size.value),
        parseFloat(rotate.value));

}, false);